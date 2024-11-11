#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int p1, p2, p3, p4, a, b;
  cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
  long long int p = min(p1, min(p2, min(p3, p4)));
  cout << max((long long int)0, min(p, b) - a + 1);
}
