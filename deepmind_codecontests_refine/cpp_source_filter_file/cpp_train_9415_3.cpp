#include <bits/stdc++.h>
using namespace std;
int main() {
  long nos, d, i;
  cin >> nos >> d;
  long a[100], st = 0;
  for (i = 0; i < nos; i++) {
    cin >> a[i];
    st = st + a[i];
  }
  if (st < d) {
    cout << "-1";
    return 0;
  }
  long noj = (d - st) / 5;
  if ((nos - 1) * 2 <= noj)
    cout << noj;
  else
    cout << "-1";
  return 0;
}
