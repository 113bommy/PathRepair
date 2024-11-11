#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, c, i;
  cin >> n >> c;
  int p[n], t[n];
  for (i = 0; i < n; ++i) {
    cin >> p[i];
  }
  for (i = 0; i < n; ++i) {
    cin >> t[i];
  }
  int scoL = 0, scoR = 0, time = 0;
  for (i = 0; i < n; ++i) {
    time += t[i];
    scoL += max(0, (p[i] - (c * time)));
  }
  --i;
  for (int time = 0; i >= 0; --i) {
    time += t[i];
    scoR += max(0, (p[i] - (c * time)));
  }
  if (scoL > scoR)
    cout << "Limak";
  else if (scoL == scoR)
    cout << "Tie";
  else
    cout << "Randewoosh";
  return 0;
}
