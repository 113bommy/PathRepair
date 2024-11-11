#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int H, L;
  cin >> H >> L;
  cout << fixed << setprecision(13) << (double)((L * L) - (H * H)) / (H + H)
       << endl;
}
