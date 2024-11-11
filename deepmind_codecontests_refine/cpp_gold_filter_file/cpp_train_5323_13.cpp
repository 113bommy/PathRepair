#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum, ns, nf, i;
  vector<int> v;
  cin >> n;
  for (i = 0; i <= n; i++) {
    sum = n - i;
    if (i % 4 == 0 && sum % 7 == 0) {
      nf = i;
      ns = sum;
      break;
    }
  }
  if (i == n + 1) {
    cout << "-1";
  } else {
    ns = ns / 7;
    nf = nf / 4;
    for (int j = 0; j < nf; j++) {
      cout << "4";
    }
    for (int k = 0; k < ns; k++) {
      cout << "7";
    }
  }
  cout << endl;
  return 0;
}
