#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
void show(long double a, int x, bool endofline, bool space) {
  cout << fixed << setprecision(x) << a;
  if (endofline) cout << endl;
  if (space) cout << ' ';
}
int readInt() {
  bool minus = false;
  int result = 0;
  char ch;
  ch = getchar();
  while (true) {
    if (ch == '-') break;
    if (ch >= '0' && ch <= '9') break;
    ch = getchar();
  }
  if (ch == '-')
    minus = true;
  else
    result = ch - '0';
  while (true) {
    ch = getchar();
    if (ch < '0' || ch > '9') break;
    result = result * 10 + (ch - '0');
  }
  if (minus)
    return -result;
  else
    return result;
}
inline void writeInt(long long n) {
  long long N = n, rev, count = 0;
  rev = N;
  if (N == 0) {
    putchar('0');
    putchar('\n');
    return;
  }
  while ((rev % 10) == 0) {
    count++;
    rev /= 10;
  }
  rev = 0;
  while (N != 0) {
    rev = (rev << 3) + (rev << 1) + N % 10;
    N /= 10;
  }
  while (rev != 0) {
    putchar(rev % 10 + '0');
    rev /= 10;
  }
  while (count--) putchar('0');
}
long long i, x, z, j;
long long ar[MAXN], ar2[MAXN];
vector<long long> v, v2;
set<long long> st;
pair<int, int> p;
string s;
bool flag2, flag;
void debug() { cout << "DEBUGGING\n"; }
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> x >> s;
  for (i = 0; i < x; i++) {
    cout << s[i];
    while ((s[i] == 'o' || s[i] == 'a' || s[i] == 'u' || s[i] == 'i' ||
            s[i] == 'e' && s[i] == 'y') &&
           i < x)
      i++;
    if (i < x && (s[i - 1] == 'o' || s[i - 1] == 'a' || s[i - 1] == 'u' ||
                  s[i - 1] == 'i' || s[i - 1] == 'e' && s[i - 1] == 'y'))
      cout << s[i];
  }
}
