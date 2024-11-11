#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
long long INF = 1LL << 60;
bool compareA(vector<int> a, vector<int> b) {
  return abs(a[0]) + abs(a[1]) < abs(b[0]) + abs(b[1]);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n, t;
  cin >> n >> t;
  string s1, s2;
  cin >> s1 >> s2;
  long long same = 0;
  for (int i = 0; i < n; i++) {
    if (s1[i] == s2[i]) {
      same++;
    }
  }
  long long diff = n - same;
  if ((n % 2 == 0 && t < diff / 2) || (n % 2 == 1 && t <= diff / 2)) {
    cout << -1;
    return 0;
  }
  string out;
  long long keepSame = min(n - t, same);
  long long keepOne = 2 * (n - keepSame - t);
  for (int i = 0; i < n; i++) {
    if (s1[i] == s2[i]) {
      if (keepSame > 0) {
        keepSame--;
        out += s1[i];
      } else {
        for (int j = 0; j < 26; j++) {
          if (j != s1[i] - 'a') {
            out += (char)(j + 'a');
            break;
          }
        }
      }
    } else {
      if (keepOne > 0) {
        if (keepOne % 2 == 0) {
          out += s1[i];
        } else {
          out += s2[i];
        }
        keepOne--;
      } else {
        for (int j = 0; j < 26; j++) {
          if (j != s1[i] - 'a' && j != s2[i] - 'a') {
            out += (char)(j + 'a');
            break;
          }
        }
      }
    }
  }
  cout << out;
}
