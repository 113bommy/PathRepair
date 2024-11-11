#include <bits/stdc++.h>
using namespace std;
int mx = 0;
char a[5], b[5];
int aint[5], bint[5];
bool iscarry(int i) {
  if (i == 4) return false;
  if (aint[i] + bint[i] >= mx)
    return true;
  else if (aint[i] + bint[i] < mx - 1)
    return false;
  else
    return iscarry(i + 1);
}
int main() {
  cin >> a >> b;
  for (int i = 3, j = strlen(a) - 1; i >= 0; i--) {
    if (j >= 0) {
      aint[i] = a[j--] - '0';
      mx = max(mx, aint[i]);
    } else
      aint[i] = 0;
  }
  for (int i = 3, j = strlen(b) - 1; i >= 0; i--) {
    if (j >= 0) {
      bint[i] = b[j--] - '0';
      mx = max(mx, bint[i]);
    } else
      bint[i] = 0;
  }
  mx++;
  int i = 0;
  while ((aint[i] + bint[i]) == 0) i++;
  if (iscarry(i))
    cout << max(strlen(a), strlen(b)) + 1 << endl;
  else
    cout << max(strlen(a), strlen(b)) << endl;
}
