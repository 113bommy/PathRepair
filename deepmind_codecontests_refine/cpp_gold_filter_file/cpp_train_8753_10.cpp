#include <bits/stdc++.h>
using namespace std;
long long x[100001];
int main() {
  long long n, k, s, del, ost, a = 1;
  cin >> n >> k >> s;
  if ((n - 1) * k < s || k > s) {
    cout << "NO";
    return 0;
  }
  cout << "YES" << endl;
  del = s / k;
  ost = s % k;
  int t;
  for (int i = 0; i < k; i++) {
    if (ost) {
      t = 1;
      ost--;
    } else
      t = 0;
    if (i % 2 == 0)
      a += del + t;
    else
      a -= (del + t);
    cout << a << " ";
  }
  return 0;
}
