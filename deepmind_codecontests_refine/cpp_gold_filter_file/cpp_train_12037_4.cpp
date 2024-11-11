#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x;
  cin >> n >> x;
  set<long long> s;
  long long val;
  for (long long i = 0; i < n; i++) {
    cin >> val;
    s.insert(val);
  }
  long long ctr = 0;
  for (long long i = 0; i < x; i++) {
    if (s.find(i) == s.end()) ctr++;
  }
  if (s.find(x) != s.end()) ctr++;
  cout << ctr;
}
