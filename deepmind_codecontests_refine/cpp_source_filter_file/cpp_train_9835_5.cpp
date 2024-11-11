#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int x;
  cin >> x;
  int cntr = 0;
  int currenttime = 1;
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;
    int r;
    cin >> r;
    currenttime += ((l - currenttime) / x) * x;
    cntr += (r + 1) - currenttime;
    currenttime++;
  }
  cout << cntr << endl;
  return 0;
}
