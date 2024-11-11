#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  vector<int> l1, l2;
  for (long long i = 1; i <= m; i++) {
    long long a, b;
    cin >> a >> b;
    if (a < b) {
      l1.push_back(a);
      l2.push_back(b);
    } else {
      l1.push_back(b);
      l2.push_back(a);
    }
  }
  if (m >= 1) {
    long long max = 0, min = 1000000;
    for (long long i = 0; i < l1.size(); i++) {
      if (max < l1[i]) max = l1[i];
    }
    for (long long i = 0; i < l2.size(); i++) {
      if (min > l2[i]) min = l2[i];
    }
    if (max >= min) {
      cout << 0 << endl;
    } else {
      long long dif = min - max;
      cout << dif << endl;
    }
  } else
    cout << n + 1 << endl;
  return 0;
}
