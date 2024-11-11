#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  vector<long long int> v;
  long long int n, m, a;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
}
