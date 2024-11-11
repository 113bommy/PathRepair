#include <bits/stdc++.h>
using namespace std;
bool compare(int a, int b) { return a > b; }
int main() {
  int n, m, k;
  int Score = 0;
  cin >> n >> m >> k;
  int Alice[n], maxAlice, minAlice;
  int Bob[m], maxBob, minBob;
  for (int i = 0; i < n; i++) {
    cin >> Alice[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> Bob[i];
  }
  maxAlice = *max_element(Alice, Alice + n);
  maxBob = *max_element(Bob, Bob + m);
  minAlice = *min_element(Alice, Alice + n);
  minBob = *min_element(Bob, Bob + m);
  sort(Alice, Alice + n, compare);
  sort(Bob, Bob + n, compare);
  if (n > m) {
    cout << "YES" << endl;
  } else {
    if (maxAlice > maxBob) {
      cout << "YES" << endl;
    } else {
      int i = 0;
      bool SolnFound = false;
      while ((i < n) && (SolnFound == false)) {
        if (Alice[i] > Bob[i]) {
          SolnFound = true;
        } else {
          i++;
        }
      }
      if (SolnFound) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
