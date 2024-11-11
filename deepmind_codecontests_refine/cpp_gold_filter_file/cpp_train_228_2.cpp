#include <bits/stdc++.h>
using namespace std;
const double acc = 1e-9;
const int MAX = 200005;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int p[MAX] = {0};
    for (int i = (int)0; (i) < (m); ++(i)) {
      int x;
      cin >> x;
      ++p[x];
    }
    long long res[26] = {0}, a2[26] = {0}, a1[26] = {0};
    int i;
    for (i = 0; i < n; i++) ++a2[s[i] - 'a'];
    for (i = 0; i < n; ++i) {
      ++a1[s[i] - 'a'];
      if (p[i + 1]) {
        for (int j = 0; j < 26; j++) a2[j] = a2[j] + p[i + 1] * a1[j];
      }
    }
    for (int i = 0; i < 26; i++) cout << a2[i] << " ";
    cout << endl;
  }
}
