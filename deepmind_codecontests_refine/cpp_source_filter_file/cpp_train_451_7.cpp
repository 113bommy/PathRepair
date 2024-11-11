#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int i, l[n], r[n], left = 0, right = 0;
  for (i = 0; i < n; i++) {
    cin >> l[i];
    cout << " ";
    cin >> r[i];
    if (l[i] == 1) left++;
    if (r[i] == 1) right++;
  }
  long long int t = 0;
  if (n % 2 == 0) {
    if (left >= n / 2)
      t = n - left;
    else
      t = left;
  } else {
    if (left > (n + 1) / 2)
      t += n - left;
    else
      t += left;
  }
  if (n % 2 == 0) {
    if (right >= n / 2)
      t += n - right;
    else
      t += right;
  } else {
    if (right > (n + 1) / 2)
      t += n - right;
    else
      t += right;
  }
  cout << t;
}
