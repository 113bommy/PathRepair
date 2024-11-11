#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s;
  cin >> n >> s;
  int k;
  int max;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> k;
    if (i == 0)
      max = k;
    else {
      if (k > max) max = k;
    }
    sum += k;
  }
  if ((sum - k) <= s)
    cout << "YES";
  else
    cout << "NO";
}
