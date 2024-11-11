#include <bits/stdc++.h>
using namespace std;
long long fact(int a) {
  if ((a == 0) || (a == 1))
    return (1);
  else
    return (a * fact(a - 1));
}
int main() {
  vector<int> t;
  vector<int> t1;
  long long int k = 0, a, j, i, n;
  cin >> n;
  cin >> a;
  t.resize(n);
  for (i = 0; i < n; i++) {
    t[i] = a % 10;
    a = a / 10;
  }
  for (i = 0; i < n; i++) {
    if (t[i] == 4) {
      t1.push_back(3);
      t1.push_back(2);
      t1.push_back(2);
      k += 2;
    } else if (t[i] == 8) {
      t1.push_back(7);
      t1.push_back(2);
      t1.push_back(2);
      t1.push_back(2);
      k += 3;
    } else if (t[i] == 6) {
      t1.push_back(5);
      t1.push_back(3);
      k += 1;
    } else if (t[i] == 9) {
      t1.push_back(7);
      t1.push_back(3);
      t1.push_back(2);
      t1.push_back(3);
      k += 3;
    } else if (t[i] < 2)
      k -= 1;
    else
      t1.push_back(t[i]);
    k += 1;
  }
  n = k;
  t1.resize(n);
  stable_sort(t1.begin(), t1.end());
  reverse(t1.begin(), t1.end());
  for (i = 0; i < n; i++) cout << t1[i];
  return 0;
}
