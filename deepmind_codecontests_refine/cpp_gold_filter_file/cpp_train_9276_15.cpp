#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int temp;
  int r;
  vector<int> freq(101);
  for (int i = 0; i < n; i++) {
    vector<bool> visited(101);
    cin >> r;
    for (int i = 0; i < r; i++) {
      cin >> temp;
      if (!visited[temp]) {
        freq[temp]++;
        visited[temp] = 1;
      }
    }
  }
  for (int i = 0; i < 101; i++) {
    if (freq[i] == n) cout << i << " ";
  }
  return 0;
}
