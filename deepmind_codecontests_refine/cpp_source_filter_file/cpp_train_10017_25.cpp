#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int ara[n];
  int odd = 0, even = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &ara[i]);
    if (ara[i] & 1)
      odd++;
    else
      even++;
  }
  if (odd & 1)
    cout << "1\n";
  else
    cout << even << "\n";
  return 0;
}
