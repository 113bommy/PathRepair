#include <bits/stdc++.h>
using namespace std;
void prime_generator(vector<int> &v) {
  int i, j, k;
  bool test;
  v.push_back(2);
  v.push_back(3);
  for (i = 5; i < 1001; i++) {
    k = i / 2;
    test = true;
    for (j = 2; j < k; j++)
      if (i % j == 0) {
        test = false;
        break;
      }
    if (test) v.push_back(i);
  }
  v.push_back(-1);
}
int main() {
  vector<int> v;
  prime_generator(v);
  bool test;
  int i, count, j, n, k;
  cin >> n >> k;
  count = 0;
  for (i = 0; v[i] <= n; i++) {
    test = false;
    for (j = 0; v[j + 1] <= n && j < i; j++) {
      if (v[j] + v[j + 1] + 1 == v[i]) {
        count++;
        break;
      }
    }
    if (count == k) {
      test = true;
      break;
    }
  }
  if (test)
    cout << "YES\n";
  else
    cout << "NO\n";
}
