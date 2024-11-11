#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> v;
  while (n--) {
    int a;
    cin >> a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  int x = 1;
  for (int i = 0; i < (int)v.size(); i++) {
    if (v[i] >= x) x++;
  }
  cout << x - 1 << "\n";
  ;
  return 0;
}
