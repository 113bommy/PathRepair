#include <bits/stdc++.h>
using namespace std;
vector<long> c(int n) {
  int i;
  vector<long> a1, a;
  if (n == 1)
    a.push_back(1);
  else if (n == 2) {
    a.push_back(1);
    a.push_back(2);
  } else if (n == 3) {
    a.push_back(1);
    a.push_back(1);
    a.push_back(3);
  } else {
    for (i = 0; i < (n + 1) / 2; i++) a.push_back(1);
    a1 = c(n / 2);
    for (auto const& it : a1) a.push_back(it * 2);
  }
  return a;
}
int main() {
  int n, i = 0;
  cin >> n;
  vector<long> a = c(n);
  n = a.size();
  for (i = 0; i < n; i++) cout << a[i] << " ";
  return 0;
}
