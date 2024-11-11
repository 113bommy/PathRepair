#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, l, c = 1, max = 0;
  cin >> n;
  vector<long long int> a;
  for (i = 0; i < n; i++) {
    cin >> l;
    a.push_back(l);
  }
  sort(a.begin(), a.end(), greater<int>());
  for (i = 0; i < n - 1; i++) {
    if (a[i] == a[i + 1]) {
      c++;
      if (c > max) {
        max = c;
      }
    } else {
      c = 1;
    }
  }
  cout << max;
  return 0;
}
