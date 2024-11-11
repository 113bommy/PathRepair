#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int count = 2, c = 2, i, a[100005], n;
  cin >> n;
  cin >> a[0] >> a[1];
  for (i = 2; i < n; i++) {
    cin >> a[i];
    if (a[i] == (a[i - 1] + a[i - 2])) {
      c++;
    } else {
      if (count < c) count = c;
      c = 0;
    }
  }
  if (count < c) count = c;
  if (n == 1)
    cout << "1";
  else {
    cout << count << endl;
  }
  return 0;
}
