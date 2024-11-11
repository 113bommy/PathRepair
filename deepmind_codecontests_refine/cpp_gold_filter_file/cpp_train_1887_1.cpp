#include <bits/stdc++.h>
using namespace std;
long long int n;
vector<long long int> v, t;
map<long long int, long long int> m;
int sum, q;
int main() {
  cin >> n;
  v = vector<long long int>(n);
  for (long long int i = 0; i < n; i++) {
    cin >> v[i];
    m[v[i]]++;
  }
  if (m.size() == 1) {
    cout << m.begin()->second << endl;
    return 0;
  }
  map<long long int, long long int>::iterator it = m.begin();
  t = vector<long long int>(m.size());
  while (it != m.end()) {
    t.push_back(it->second);
    it++;
  }
  sort(t.begin(), t.end());
  for (int i = 0; i <= t.back(); i++) {
    int cur = i;
    int pos = t.size() - 1;
    int res = cur;
    while (cur % 2 == 0 && pos > 0) {
      cur /= 2;
      pos--;
      if (t[pos] < cur) break;
      res += cur;
    }
    sum = max(sum, res);
  }
  cout << sum << endl;
  return 0;
}
