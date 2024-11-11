#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v;
  int i = 0;
  int temp;
  while (i < n) {
    cin >> temp;
    v.push_back(temp);
    i++;
  }
  int ans = 0;
  sort(v.begin(), v.end());
  int min = 1000000000;
  for (int i = 0; i < n - 1; ++i) {
    if ((v[i + 1] - v[i]) < min) min = v[i + 1] - v[i];
  }
  for (int i = 0; i < n - 1; ++i) {
    if ((v[i + 1] - v[i]) == min) ans++;
  }
  cout << min << " " << ans << "\n";
}
