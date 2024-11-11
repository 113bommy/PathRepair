#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> doors(n);
  int last_door_position = n;
  for (int i = 0; i < n; i++) cin >> doors[i];
  for (int k = n - 1; 0 < k; k--) {
    if (doors[k] != doors[n - 1]) {
      cout << k + 1 << '\n';
      break;
    }
  }
}
