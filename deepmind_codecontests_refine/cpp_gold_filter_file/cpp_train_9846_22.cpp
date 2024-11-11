#include <bits/stdc++.h>
using namespace std;
using ii = int;
int main() {
  ii n, i;
  cin >> n;
  ii* ar = (ii*)malloc(sizeof(ii) * n);
  for (i = 0; i < n; i++) {
    cin >> ar[i];
  }
  ii max = *max_element(ar, ar + n);
  if (n == 1)
    cout << max - max << endl;
  else {
    ii count = 0;
    for (i = 0; i < n; i++) {
      count = count + max - ar[i];
    }
    cout << count << endl;
  }
  return 0;
}
