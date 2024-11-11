#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
bool valid(char C) {
  return ('a' <= C && 'z' >= C) || ('A' <= C && 'Z' >= C) ||
         ('0' <= C && '9' >= C) || C == '_';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string S;
  cin >> S;
  int ap = -1;
  for (int i = 0; i < ((int)(S).size()); i++) {
    if (S[i] == '@') {
      if (i == 0) {
        cout << "NO" << nl;
        return 0;
      }
      ap = i;
      break;
    }
    if (!valid(S[i])) {
      cout << "NO" << nl;
      return 0;
    }
  }
  if (ap == -1 || ap > 16) {
    cout << "NO" << nl;
    return 0;
  }
  int lst = ap;
  int sp = (int)(S).size();
  for (int i = ap + 1; i < ((int)(S).size()); i++) {
    if (S[i] == '.') {
      if (i - lst > 17 || i - lst == 1) {
        cout << "NO" << nl;
        return 0;
      }
    }
    if (S[i] == '/') {
      sp = i;
    } else if (S[i] == '.') {
      lst = i;
    } else if (!valid(S[i])) {
      cout << "NO" << nl;
      return 0;
    }
  }
  if (sp - lst > 17 || sp - lst == 1) {
    cout << "NO" << nl;
    return 0;
  }
  if ((int)(S).size() - sp > 17 || (int)(S).size() - sp == 1) {
    cout << "NO" << nl;
    return 0;
  }
  for (int i = sp; i < ((int)(S).size()); i++) {
    if (!valid(S[i])) {
      cout << "NO" << nl;
      return 0;
    }
  }
  cout << "YES" << nl;
  return 0;
  return 0;
}
