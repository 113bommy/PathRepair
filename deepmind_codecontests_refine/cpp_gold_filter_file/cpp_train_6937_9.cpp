#include <bits/stdc++.h>
using namespace std;
int n, pos, L, R;
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  scanf("%d%d%d%d", &n, &pos, &L, &R);
  if ((L == 1) && (R == n))
    cout << 0;
  else if (L == 1)
    cout << (abs(pos - R) + 1);
  else if (R == n)
    cout << (abs(pos - L) + 1);
  else {
    if (pos >= L && pos <= R)
      cout << ((R - L) + (min(abs(pos - L), abs(R - pos))) + 2);
    else
      cout << ((R - L) + min(abs(pos - L), abs(R - pos)) + 2);
  }
  return 0;
}
