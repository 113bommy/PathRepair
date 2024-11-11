#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, f;
  string a;
  cin >> n >> k;
  vector<string> names(n);
  for (int i = 0; i < n; ++i) {
    names[i].push_back(rand() % 25 + 60);
    f = rand() % 9 + 1;
    for (int j = 0; j < f; ++j) names[i].push_back(rand() % 25 + 97);
  }
  for (int i = 0; i < n - k + 1; ++i) {
    cin >> a;
    if (a == "NO") names[i + k - 1] = names[i];
  }
  for (int i = 0; i < n; ++i) cout << names[i] << " ";
  return 0;
}
