#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x7fffffffffffffff;
const int inf = 0x7fffffff;
const double eps = 1e-8;
const int N = 2e5 + 5;
clock_t start, finish;
void time_in() { start = clock(); }
void time_out() {
  finish = clock();
  double tim = (double)(finish - start) / CLOCKS_PER_SEC;
  printf("Running time is %lf\n", tim);
}
inline long long mul(long long a, long long b) {
  long long s = 0;
  while (b) {
    if (b & 1) s = (s + a) % 1000000007;
    a = (a << 1) % 1000000007;
    b >>= 1;
  }
  return s % 1000000007;
}
inline long long pow_mul(long long a, long long b) {
  long long s = 1;
  while (b) {
    if (b & 1) s = mul(s, a);
    a = mul(a, a);
    b >>= 1;
  }
  return s;
}
inline long long poww(long long a, long long b) {
  long long s = 1;
  while (b) {
    if (b & 1) s = (s * a) % 1000000007;
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return s % 1000000007;
}
inline int read() {
  char c = getchar();
  int sgn = 1, ret = 0;
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') sgn = -1, c = getchar();
  while (c >= '0' && c <= '9') ret = ret * 10 + c - 48, c = getchar();
  return ret * sgn;
}
void write(int x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline long long phi(long long x) {
  long long ans = x;
  for (long long i = 2; i * i <= x; i++)
    if (x % i == 0) {
      ans -= ans / i;
      while (x % i == 0) x /= i;
    }
  if (x > 1) ans -= ans / x;
  return ans;
}
long long inv(long long down) {
  return down == 1
             ? 1
             : ((1000000007 - 1000000007 / down) * inv(1000000007 % down)) %
                   1000000007;
}
int st[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int t, cas;
int n, m, k;
string s[N];
map<string, int> q;
int ans[N];
int a00[N], a01[N], a10[N], a11[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int cnt00, cnt01, cnt10, cnt11;
  cin >> t;
  while (t--) {
    q.clear();
    cnt00 = cnt01 = cnt11 = cnt10 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> s[i];
      q[s[i]]++;
      int len = s[i].size();
      if (s[i][0] == '0') {
        if (s[i][len - 1] == '0') {
          a00[cnt00++] = i;
        } else {
          a01[cnt01++] = i;
        }
      } else {
        if (s[i][len - 1] == '0') {
          a10[cnt10++] = i;
        } else {
          a11[cnt11++] = i;
        }
      }
    }
    if (cnt01 + cnt10 == 0) {
      if (cnt00 && cnt11) {
        cout << -1 << "\n";
        continue;
      } else {
        cout << 0 << "\n\n";
        continue;
      }
    }
    int tmp;
    if (cnt10 > cnt01) {
      if (cnt10 == cnt01 + 1)
        cout << 0 << "\n\n";
      else {
        tmp = (cnt10 - cnt01) / 2;
        int cnt = 0;
        for (int i = 0; i < cnt10 && cnt < tmp; i++) {
          reverse(s[a10[i]].begin(), s[a10[i]].end());
          if (q[s[a10[i]]]) continue;
          ans[cnt++] = a10[i];
        }
        if (cnt != tmp)
          printf("-1\n");
        else {
          cout << tmp << "\n";
          for (int i = 0; i < tmp; i++) {
            cout << ans[i];
            cout << (i == tmp - 1 ? "\n" : " ");
          }
        }
      }
    } else if (cnt01 > cnt10) {
      if (cnt01 == cnt10 + 1)
        cout << 0 << "\n\n";
      else {
        tmp = (cnt01 - cnt10) / 2;
        int cnt = 0;
        for (int i = 0; i < cnt01 && cnt < tmp; i++) {
          reverse(s[a01[i]].begin(), s[a01[i]].end());
          if (q[s[a01[i]]]) continue;
          ans[cnt++] = a01[i];
        }
        if (cnt != tmp)
          printf("-1\n");
        else {
          cout << tmp << "\n";
          for (int i = 0; i < tmp; i++) {
            cout << ans[i];
            cout << (i == tmp - 1 ? "\n" : " ");
          }
        }
      }
    } else
      cout << 0 << "\n\n";
  }
  cout << endl;
}
