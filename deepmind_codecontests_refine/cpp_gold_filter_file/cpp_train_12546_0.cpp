#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long a[n];
  int i, j, k, l;
  long long s = 0;
  long long minodd = 1000000007;
  int numodd = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2 == 1) {
      numodd++;
      minodd = min(minodd, a[i]);
    }
    s += a[i];
  }
  if (numodd % 2 == 0) {
    cout << s;
  } else
    cout << s - minodd;
}
