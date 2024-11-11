#include <bits/stdc++.h>
using namespace std;
map<int, int> m, m1;
map<int, int>::iterator it, it1;
void fun() {
  for (int i = 0; i < 100000; i++) {
    m[i] = 0;
    m1[i] = 0;
  }
}
int main() {
  long long int n, a, b, c, d, l, sum = 0;
  scanf("%I64d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%I64d %I64d", &a, &b);
    m[a] = b;
  }
  scanf("%I64d", &l);
  for (int i = 0; i < l; i++) {
    scanf("%I64d %I64d", &c, &d);
    m1[c] = d;
  }
  for (it = m.begin(); it != m.end(); it++) {
    if (m[it->first] > m1[it->first]) {
      sum += it->second;
      m1[it->first] = 0;
      m[it->first] = 0;
    }
  }
  for (it1 = m1.begin(); it1 != m1.end(); it1++) {
    if (m1[it1->first] > m[it1->first]) {
      sum += it1->second;
      m1[it1->first] = 0;
      m[it1->first] = 0;
    }
  }
  cout << sum;
  return 0;
}
