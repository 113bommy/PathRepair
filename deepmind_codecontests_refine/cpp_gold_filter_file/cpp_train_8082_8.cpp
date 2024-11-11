#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const long long N = 1e5 + 5;
int main() {
  long long n, i, j, e, o, k;
  cin >> n;
  j = e = o = 0;
  while (n--) {
    cin >> k;
    (k % 2) ? o++ : e++;
  }
  k = o;
  if (o > e) {
    k = e;
    o -= e;
    k += o / 3;
  }
  cout << k << endl;
}
