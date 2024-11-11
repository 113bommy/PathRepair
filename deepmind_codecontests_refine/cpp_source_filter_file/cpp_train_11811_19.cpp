#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n - 1);
  for (auto &x : a) cin >> x;
  sort((a).begin(), (a).end());
  for (int i = 0; i < n - 1; i++)
    if (i + 1 != a[i]) return cout << i + 1, 0;
}
