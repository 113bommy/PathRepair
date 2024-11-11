#include <bits/stdc++.h>
using namespace std;
int n, a[100005], c[2];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n;
  for (int i = (1); i <= (n); ++i) cin >> a[i];
  int l = 1, r = n;
  for (int i = (1); i <= (n); ++i)
    if (i & 1) {
      if (a[l] < a[r])
        c[1] += a[r--];
      else
        c[1] += c[l++];
    } else {
      if (a[l] < a[r])
        c[0] += a[r--];
      else
        c[0] += c[l++];
    }
  cout << c[1] << ' ' << c[0];
}
