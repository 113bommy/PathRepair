#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long QPow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
const int MX = 1;
int vis[MX + 2];
int prim[MX + 2];
int top;
void init() {
  vis[0] = vis[1] = 1;
  for (int i = 2; i <= MX; i++) {
    if (!vis[i]) prim[top++] = i;
    for (int j = 0; j < top && prim[j] * i <= MX; j++) {
      vis[prim[j] * i] = 1;
      if (i % prim[j] == 0) break;
    }
  }
}
int vis1[MX + 2];
int prim1[MX + 2];
int top1;
void init1() {
  vis[0] = vis[1] = 1;
  int temp = 1;
  for (int i = 2; i <= MX; i++) {
    if (!vis[i]) {
      for (int j = 2; j * i <= MX; j++) {
        vis[j * i]++;
        temp = j;
        while (temp % i == 0) vis[j * i]++, temp /= i;
      }
      vis[i]++;
    }
  }
}
long long toInt(string str) {
  long long ans = 0;
  for (int i = 0; i < str.size(); i++) {
    ans *= 10;
    ans += str[i] - '0';
  }
  return ans;
}
string toString(long long a) {
  if (a == 0) return "0";
  string temp = "";
  long long tp = a;
  while (tp) {
    temp.push_back('0' + tp % 10);
    tp /= 10;
  }
  string temp2 = temp;
  for (int ii = 0; ii < temp.size(); ii++) {
    temp[ii] = temp2[temp.size() - 1 - ii];
  }
  return temp;
}
const int MAXN = 1;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int b[4][4];
int ans[4][4];
int md[4][4];
inline long long add(const long long &a, const long long &b) {
  return (a + b) >= mod ? (a + b) - mod : (a + b < 0 ? (a + b) + mod : a + b);
}
inline long long mul(const long long &a, const long long &b) {
  return 1LL * a * b % mod;
}
void matrixPow(int n) {
  while (n) {
    if (n & 1) {
      for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
          md[i][j] = 0;
          for (int k = 0; k < 4; k++)
            md[i][j] = add(md[i][j], mul(ans[i][k], b[k][j]));
        }
      memcpy(ans, md, sizeof ans);
    }
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++) {
        md[i][j] = 0;
        for (int k = 0; k < 4; k++)
          md[i][j] = add(md[i][j], mul(b[i][k], b[k][j]));
      }
    memcpy(b, md, sizeof b);
    n >>= 1;
  }
}
inline void read(int &n) {
  char c = '+';
  bool flag = 0;
  n = 0;
  while (c < '0' || c > '9') {
    c = getchar();
    if (c == '-') flag = 1;
  }
  while (c >= '0' && c <= '9') n = n * 10 + c - 48, c = getchar();
}
int arr[100005];
int bb[100005];
signed main() {
  ifstream in("Text.txt");
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  int n;
  int m;
  cin >> n;
  cin >> t;
  string ss, tt;
  cin >> ss >> tt;
  string temp = ss;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (ss[i] != tt[i]) cnt++;
  }
  if (cnt > 2 * t) {
    cout << -1 << endl;
  } else {
    int ptr = 0, cnt1 = 0;
    int up = max(0, cnt - t);
    string ans1;
    for (int i = ptr; i < n && cnt1 < up; i++) {
      if (ss[i] != tt[i]) {
        cnt1++;
        temp[i] = tt[i];
      }
      ptr++;
    }
    cnt1 = 0;
    for (int i = ptr; i < n && cnt1 < up; i++) {
      if (ss[i] != tt[i]) {
        cnt1++;
        temp[i] = ss[i];
      }
      ptr++;
    }
    int cnt2 = cnt - up;
    for (int i = ptr; i < n; i++)
      if (ss[i] != tt[i]) {
        cnt2--;
        for (int j = 0; j < 26; j++)
          if ('a' + j != ss[i] && 'a' + j != tt[i]) temp[i] = 'a' + j;
      }
    if (cnt2 != 0) {
      for (int i = 0; i < n; i++)
        if (ss[i] == tt[i]) {
          temp[i] = (ss[i] - 'a' + 1) % 26 + 'a';
          cnt2--;
          if (cnt2 <= 0) break;
        }
    }
    cout << temp << endl;
  }
  return 0;
}
