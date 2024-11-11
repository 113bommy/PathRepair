#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, c;
  cin >> n >> m;
  vector<long long> v, a;
  long long b;
  for (int i = 0; i < n; i++) {
    cin >> b;
    a.push_back(b);
  }
  sort(a.begin(), a.end());
  c = m;
  for (int i = 1; i <= 100000; i++) {
    bool t;
    t = binary_search(a.begin(), a.end(), i);
    if (t == false && (c - i) >= 0) v.push_back(i), c -= i;
  }
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  return 0;
}
