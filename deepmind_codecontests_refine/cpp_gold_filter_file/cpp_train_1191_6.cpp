#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, a, k = 0, d, k1, k2, s = 0, e = 0;
  vector<long> v1, v2;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    v1.push_back(a);
    v2.push_back(a);
  }
  sort(v2.begin(), v2.end());
  for (int i = 0; i < n; i++) {
    if (v1[i] != v2[i]) {
      if (k == 0) {
        s = i;
        k++;
      } else
        e = i;
    }
  }
  d = e - s;
  k1 = s;
  k2 = e;
  long temp;
  if (d % 2 == 0) {
    for (int i = 0; i < d / 2; i++) {
      temp = v1[k1];
      v1[k1] = v1[k2];
      v1[k2] = temp;
      k1++;
      k2--;
    }
  } else {
    for (int i = 0; i < d / 2 + 1; i++) {
      temp = v1[k1];
      v1[k1] = v1[k2];
      v1[k2] = temp;
      k1++;
      k2--;
    }
  }
  for (int i = 0; i < n; i++) {
    if (v1[i] != v2[i]) {
      cout << "no";
      return 0;
    }
  }
  cout << "yes" << endl << s + 1 << " " << e + 1;
}
