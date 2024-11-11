#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  int line[n];
  vector<int> start;
  for (int i = 0; i < n; i++) {
    cin >> m;
    start.push_back(m + i);
  }
  sort(start.begin(), start.end());
  for (int i = 0; i < n; i++) line[i] = start[i] - i;
  for (int i = 0; i < n; i++) {
    if (n == 1) break;
    if (line[i] > line[i + 1]) {
      cout << ":(";
      return 0;
    }
  }
  for (int i = 0; i < n; i++) cout << line[i] << " ";
  return 0;
}
