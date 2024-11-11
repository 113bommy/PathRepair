#include <bits/stdc++.h>
using namespace std;
int N, evn, odd;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  cin >> N;
  for (int i = 1, a; i <= N; i++) {
    cin >> a;
    if (a & 1)
      odd++;
    else
      evn++;
  }
  if (evn > odd)
    cout << odd << "\n";
  else
    cout << (evn + (odd - evn) / 3) << "\n";
}
