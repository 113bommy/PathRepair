#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n;
  k = n;
  set<int> s;
  while (n % 2 == 0) {
    s.insert(2);
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      s.insert(i);
      n = n / i;
    }
  }
  if (n > 2) s.insert(n);
  if (s.size() == 0)
    cout << k;
  else if (s.size() == 1)
    cout << *s.begin();
  else
    cout << 1;
}
