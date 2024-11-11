#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 1], b[n + 1][2];
  for (int i = 0; i < n; ++i) {
    cin >> a[i + 1];
    b[i + 1][0] = -1;
    b[i + 1][1] = -1;
  }
  for (int i = 1; i <= n; ++i) {
    int j = i + 1;
    while (j <= n && a[j] % a[i] == 0) j++;
    b[i][0] = j - 1;
    i = --j;
  }
  for (int i = n; i >= 1; --i) {
    if (b[i][0] == -1)
      continue;
    else {
      int j = i - 1;
      while (j >= 1 && a[j] % a[i] == 0) j--;
      b[i][1] = j + 1;
      i = ++j;
    }
  }
  int max = -1;
  for (int i = 1; i <= n; ++i) {
    if (b[i][0] != -1 && b[i][1] != -1) {
      if (b[i][0] - b[i][1] > max) max = b[i][0] - b[i][1];
    }
  }
  vector<int> v1;
  for (int i = 1; i <= n; ++i) {
    if (b[i][0] != -1 && b[i][1] != -1) {
      if (max == b[i][0] - b[i][1]) v1.push_back(b[i][1]);
    }
  }
  sort(v1.begin(), v1.end());
  cout << v1.size() << " " << max << "\n";
  for (int i = 0; i < v1.size(); ++i) cout << v1[i] << " ";
}
