#include <bits/stdc++.h>
using namespace std;
void maloosh_lazma() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  maloosh_lazma();
  int n, x, xx, tot = 0, tot2 = 0;
  cin >> n;
  while (n--) {
    cin >> x >> xx;
    if (xx < x) {
      tot++;
    }
    if (xx > x) tot2++;
  }
  tot == tot2  ? cout << "Friendship is magic!^^"
  : tot > tot2 ? cout << "Misha"
               : cout << "Chris";
  return 0;
}
