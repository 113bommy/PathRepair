#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  unordered_set<long long> s;
  s.insert(n);
  while (1) {
    n++;
    while (n % 10 == 0) n /= 10;
    if (s.find(n) == s.end()) break;
    s.insert(n);
  }
  cout << s.size();
}
