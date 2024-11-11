#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum_a = 0, sum_b = 0;
  cin >> n;
  int l;
  vector<int> a;
  vector<int> b;
  for (int i = 0; i < n; i++) {
    cin >> l;
    a.push_back(l);
  }
  int p;
  for (int i = 0; i < n; i++) {
    cin >> p;
    if (p == 1 && a[i] == 1) {
      a[i] = 0;
      p = 0;
    }
    b.push_back(p);
    sum_a += a[i];
    sum_b += b[i];
  }
  float k = 0;
  if (sum_a == sum_b || sum_a == 0) {
    cout << "-1";
    exit(0);
  }
  k = sum_b / sum_a;
  int kk = floor(k);
  if (kk > sum_b) {
    cout << kk;
  } else {
    cout << (k + 1);
  }
  return 0;
}
