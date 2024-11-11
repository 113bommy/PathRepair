#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a;
  for (int i = 1; i <= n; i++) {
    int temp;
    cin >> temp;
    a.push_back({temp, i});
  }
  sort(a.begin(), a.end());
  vector<int> t1, t2;
  long long s1 = 0, s2 = 0;
  for (int i = 0; i < a.size(); i++) {
    if (s1 - s2 < a[0].first)
      s1 += a[i].first, t1.push_back(a[i].second);
    else
      s2 += a[i].first, t2.push_back(a[i].second);
  }
  cout << t1.size() << endl;
  for (int x : t1) cout << x << " ";
  cout << endl;
  cout << t2.size() << endl;
  for (int x : t2) cout << x << " ";
}
