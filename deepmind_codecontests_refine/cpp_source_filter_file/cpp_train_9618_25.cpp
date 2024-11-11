#include <bits/stdc++.h>
const long long MOD = 1e9 + 7;
const long long MAXN = 1e6 + 1;
using namespace std;
long long readInt() {
  bool minus1 = false;
  long long result = 0;
  char ch;
  ch = getchar();
  while (true) {
    if (ch == '-') break;
    if (ch >= '0' && ch <= '9') break;
    ch = getchar();
  }
  if (ch == '-')
    minus1 = true;
  else
    result = ch - '0';
  while (true) {
    ch = getchar();
    if (ch < '0' || ch > '9') break;
    result = result * 10 + (ch - '0');
  }
  if (minus1)
    return -result;
  else
    return result;
}
const int N = 5001;
int mexx[N];
bool g[N];
int main() {
  string s;
  cin >> s;
  for (int i = 1; i < N; i++) {
    memset(mexx, 0, sizeof(mexx));
    for (int j = 0; j < i; j++) {
      int L = max(0, j - 1);
      int R = max(0, i - j - 2);
      int res = (g[L] ^ g[R]);
      if (res < N) mexx[res] = 1;
    }
    for (int j = 0;; j++) {
      if (!mexx[j]) {
        g[i] = j;
        break;
      }
    }
  }
  int n = s.size();
  int ans = 0;
  for (int i = 1; i < n - 1; i++) {
    if (s[i - 1] == s[i + 1]) {
      int j = i;
      while (j + 2 < n && s[j] == s[j + 2]) {
        j++;
      }
      ans ^= (g[j - i + 1]);
      i = j + 1;
    }
  }
  if (ans == 0) {
    cout << "Second";
    return 0;
  } else {
    cout << "First" << '\n';
    for (int i = 1; i < n - 1; i++) {
      if (s[i - 1] == s[i + 1]) {
        int j = i;
        while (j + 2 < n && s[j] == s[j + 2]) {
          j++;
        }
        int len = (j - i + 1);
        int tmp = ans ^ g[len];
        for (int k = 0; k < len; k++) {
          int L = max(0, k - 1);
          int R = max(0, len - k - 2);
          int rez = tmp ^ (g[L] ^ g[R]);
          if (rez == 0) {
            cout << i + k + 1;
            return 0;
          }
        }
        i = j + 1;
      }
    }
  }
  return 0;
}
