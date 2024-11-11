#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int j = 0; j < t; j++) {
    int n;
    cin >> n;
    vector<int> szamok;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      szamok.push_back(a);
    }
    sort(szamok.begin(), szamok.end());
    int baj = 0;
    for (int i = 0; i < n; i++) {
      if (szamok[i + 1] - szamok[i] > 1) {
        baj++;
      }
    }
    if (baj > 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
