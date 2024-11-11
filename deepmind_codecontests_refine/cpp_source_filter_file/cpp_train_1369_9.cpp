#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long int n, i, t, t1, j;
  cin >> n;
  long long int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  i = 0;
  while (i < n) {
    t = t + 1;
    j = i;
    t1 = a[i];
    while (((j + 1) <= t1) && j < n) {
      if (a[j] > t1) t1 = a[j];
      j++;
    }
    i = t1;
  }
  cout << t;
}
