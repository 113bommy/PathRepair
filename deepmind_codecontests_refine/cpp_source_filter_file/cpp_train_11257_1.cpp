#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const double EPS = 1e-9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k, length, A[64] = {};
  string s;
  char before;
  cin >> n >> k >> s;
  length = 0;
  for (int i = 0; i <= n - k; i++) {
    if (!i) {
      before = s[i];
      length = 1;
    } else {
      if (s[i] == before)
        length++;
      else {
        before = s[i];
        length = 1;
      }
    }
    if (length == k) {
      A[before - 'a']++;
      length = 0;
    }
  }
  length = 0;
  for (int i = 0; i < 64; i++) length = max(length, A[i]);
  cout << length << '\n';
}
