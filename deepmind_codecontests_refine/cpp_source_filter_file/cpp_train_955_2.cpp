#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int q;
  cin >> q;
  for (long long int qq = 0; qq < q; qq++) {
    long long int n, r, i;
    cin >> n >> r;
    set<long long int> s;
    for (long long int i = 0; i < n; i++) {
      long long int a;
      cin >> a;
      s.insert(a);
    }
    std::vector<long long int> v;
    auto it = s.begin();
    for (; it != s.end(); it++) {
      v.push_back(*it);
    }
    int y = 0;
    for (i = 1; i < v.size(); i++) {
      if ((v[v.size() - i - 1] - i * r) <= 0) {
        cout << i << "\n";
        y = 1;
        break;
      }
    }
    if (y == 0) {
      cout << v.size();
    }
  }
  return 0;
}
