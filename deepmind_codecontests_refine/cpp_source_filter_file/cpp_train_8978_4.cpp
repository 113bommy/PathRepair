#include <bits/stdc++.h>
using namespace std;
static const int SIZE = 13;
int t, n, tab[SIZE], visited[SIZE], actual_max, last_max_poz, values[SIZE],
    backpack[SIZE];
const bool DEBUG = false;
int main() {
  cin >> t;
  while (t--) {
    for (int i = 0; i < SIZE; i++)
      tab[i] = visited[i] = values[i] = backpack[i] = 0;
    if (DEBUG) cout << "###############################\n";
    cin >> n;
    n = n * 2;
    for (int i = 0; i < n; i++) {
      cin >> tab[i];
    }
    actual_max = n;
    last_max_poz = n;
    for (int i = n - 1; i >= 0; i--) {
      visited[tab[i]] = 1;
      if (tab[i] == actual_max) {
        values[last_max_poz - i]++;
        if (DEBUG) cout << last_max_poz - i << " ";
        last_max_poz = i;
        while (actual_max >= 0 && visited[actual_max]) {
          actual_max--;
        }
      }
    }
    if (DEBUG) cout << "\n";
    backpack[0] = 1;
    for (int i = n; i > 0; i--) {
      if (values[i] > 0) {
        for (int x = n / 2 + 2; x >= 0; x--) {
          if (backpack[x]) {
            int k = x;
            for (int j = 1; j <= values[i] && k <= n / 2 + 3; j++) {
              k += i;
              if (backpack[k] == 0) {
                backpack[k] = 1;
              } else {
                break;
              }
            }
          }
        }
      }
    }
    if (DEBUG) {
      cout << n << "\n";
      for (int i = 0; i < n; i++) cout << backpack[i] << " ";
      cout << "\n";
    }
    if (backpack[n / 2])
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
