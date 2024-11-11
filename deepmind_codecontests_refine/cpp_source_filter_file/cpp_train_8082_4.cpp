#include <bits/stdc++.h>
using namespace std;
long long b[500000];
int a[500000];
int main() {
  long long n;
  map<int, int> m1, m2;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    if (x % 2 == 0)
      m1[x]++;
    else
      m2[x]++;
  }
  if (m1.size() > m2.size()) {
    cout << m2.size() << endl;
  } else if (m1.size() == m2.size())
    cout << m1.size() << endl;
  else {
    long long p = m2.size() - m1.size();
    p = p % 3;
    p += m1.size();
    cout << p << endl;
  }
}
