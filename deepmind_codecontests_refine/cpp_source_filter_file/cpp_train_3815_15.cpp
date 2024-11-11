#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e5 + 100;
const int Mode = 1e9 + 7;
int High[Maxn], Par[Maxn], n, m;
int Get_Par(int x) { return Par[x] == x ? x : Get_Par(Par[x]); }
void Merge(int x, int y) {
  x = Get_Par(x);
  y = Get_Par(y);
  if (High[x] < High[y])
    Par[x] = y;
  else if (High[x] > High[y])
    Par[y] = x;
  else {
    High[x]++;
    Par[y] = x;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  for (int i = 1; i < Maxn; i++) Par[i] = i;
  cin >> n >> m;
  long long Res = 1, l, r;
  while (m--) {
    cin >> l >> r;
    if (Get_Par(l) != Get_Par(r))
      Merge(l, r);
    else
      Res = (2LL * Res + Mode) % Mode;
    cout << (Res == 0 ? Mode - 1 : Res - 1) << endl;
  }
}
