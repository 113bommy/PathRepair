#include <bits/stdc++.h>
long long int a[100000];
using namespace std;
int main() {
  long long int i, j, n, t, a, b, s = 1;
  map<long long int, long long int> mp;
  map<long long int, long long int>::iterator it;
  vector<long long int> v;
  list<long long int> l;
  string s1;
  cin >> a >> b;
  if (a == 0) a = 1;
  if (b == 0) b = 1;
  if (b - a > 10)
    cout << ")" << endl;
  else {
    for (i = a + 1; i <= b; i++) {
      s *= i % 10;
    }
    cout << (s % 10) << endl;
  }
  return 0;
}
