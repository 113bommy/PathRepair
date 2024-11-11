#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  vector<int> v;
  vector<int>::iterator it;
  cin >> n >> a;
  v.push_back(a);
  for (int i = 1; i < n; i++) {
    cin >> a;
    while (a == v.back()) {
      a++;
      v.erase(v.begin() + v.size() - 1);
    }
    v.push_back(a);
  }
  cout << v.size() << '\n';
  for (it = v.begin(); it < v.end(); it++) cout << *it << '\t';
}
