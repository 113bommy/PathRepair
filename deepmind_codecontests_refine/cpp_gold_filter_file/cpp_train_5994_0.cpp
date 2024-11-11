#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
vector<int> v;
int n, cnt, lnt, mx;
string m;
set<string> a;
int main() {
  cin >> m;
  for (int i = 1; i <= m.size(); i++) {
    for (int j = 0; j < m.size() - 1; j++) {
      swap(m[j], m[j + 1]);
    }
    a.insert(m);
  }
  cout << a.size();
}
