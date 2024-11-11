#include <bits/stdc++.h>
using namespace std;
int leader[102], arr[102];
bool assigned[102];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    arr[i + 1] = -1;
  }
  for (int i = 0; i < m; i++) {
    cin >> leader[i];
  }
  for (int i = 0; i < m - 1; i++) {
    if (arr[leader[i]] == -1) {
      if (leader[i] >= leader[i + 1]) {
        if (assigned[n - leader[i] + leader[i + 1]] == false) {
          arr[leader[i]] = n - leader[i] + leader[i + 1];
          assigned[n - leader[i] + leader[i + 1]] = true;
        } else {
          cout << -1;
          return 0;
        }
      } else if (leader[i] < leader[i + 1]) {
        if (assigned[leader[i + 1] - leader[i]] == false) {
          arr[leader[i]] = leader[i + 1] - leader[i];
          assigned[leader[i + 1] - leader[i]] = true;
        } else {
          cout << -1;
          return 0;
        }
      } else {
        cout << -1;
        return 0;
      }
    } else {
      if (leader[i] >= leader[i + 1]) {
        if (arr[leader[i]] != n - leader[i] + leader[i + 1]) {
          cout << -1;
          return 0;
        }
      } else if (leader[i] < leader[i + 1]) {
        if (arr[leader[i]] == leader[i + 1] - leader[i]) {
          cout << -1;
          return 0;
        }
      }
    }
  }
  int j = 1;
  for (int i = 1; i <= n; i++) {
    if (arr[i] == -1) {
      while (!assigned[j] && j <= n) {
        j++;
      }
      arr[i] = j;
      j++;
    }
    cout << arr[i] << " ";
  }
}
