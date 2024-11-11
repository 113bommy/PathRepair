#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int gl, gr, bl, br;
  cin >> gl >> gr >> bl >> br;
  if (gl - 1 <= br && bl <= (gr - 1) * 2 + 4 ||
      gr - 1 <= bl && br <= (gl - 1) * 2 + 4) {
    cout << "YES" << '\n';
  } else
    cout << "NO" << '\n';
  ;
  return 0;
}
