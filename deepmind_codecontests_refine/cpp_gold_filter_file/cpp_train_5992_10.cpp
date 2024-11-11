#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<pair<int, int> > v;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    v.push_back({a, i});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n / 2; i++) {
    cout << v[i].second << " " << v[n - i - 1].second << endl;
  }
}
