#include <bits/stdc++.h>
using namespace std;
int a[1010];
int b[1010];
long long sa[1010];
long long sb[1010];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  sa[0] = a[0];
  sb[0] = b[0];
  long long Ma = 0, Mb = 0;
  for (int i = 1; i < n; i++) {
    sa[i] = sa[i - 1] | a[i];
    sb[i] = sb[i - 1] | b[i];
    Ma = max(Ma, sa[i]);
    Mb = max(Mb, sb[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      Ma = max(Ma, sa[i] | sa[j]);
      Mb = max(Mb, sb[i] | sb[j]);
    }
  }
  cout << Ma + Mb;
}
