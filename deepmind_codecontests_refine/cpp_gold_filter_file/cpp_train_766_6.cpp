#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  vector<long long> b, c, d;
  for (long long i = 0; i < n; i++) {
    if (a[i] > 0)
      b.push_back(a[i]);
    else if (a[i] < 0)
      c.push_back(a[i]);
    else if (a[i] == 0)
      d.push_back(a[i]);
  }
  if (c.size() % 2 == 0 && c.size() != 0) {
    d.push_back(c[c.size() - 1]);
    c.pop_back();
  }
  if (b.size() == 0) {
    b.push_back(c[c.size() - 2]);
    b.push_back(c[c.size() - 1]);
    c.pop_back();
    c.pop_back();
  }
  cout << c.size() << " ";
  for (int i = 0; i < c.size(); i++) cout << c[i] << " ";
  ;
  cout << "\n";
  cout << b.size() << " ";
  for (int i = 0; i < b.size(); i++) cout << b[i] << " ";
  ;
  cout << "\n";
  cout << d.size() << " ";
  for (int i = 0; i < d.size(); i++) cout << d[i] << " ";
  ;
  cout << "\n";
}
