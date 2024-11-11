#include <bits/stdc++.h>
using namespace std;
const int N = 110000;
int n, t[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n;
  int sumtime = 0;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    sumtime += t[i];
  }
  int id = 1, suma = 0;
  for (int i = 0; i < n; i++) {
    suma += t[i];
    if (suma > sumtime / 2) {
      id = i;
      break;
    }
  }
  suma -= t[id];
  int sumb = 0;
  for (int i = id + 1; i < n; i++) sumb += t[i];
  if (suma == sumb)
    cout << id + 1 << " " << n - id - 1 << endl;
  else
    cout << id << " " << n - id << endl;
  return 0;
}
