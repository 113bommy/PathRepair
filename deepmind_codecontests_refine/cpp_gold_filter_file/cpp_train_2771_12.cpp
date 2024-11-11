#include <bits/stdc++.h>
using namespace std;
bool num[3000000];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, cnt = 0;
  cin >> n;
  vector<int> k(n), K(n);
  for (int i = 0; i < n; i++) {
    cin >> k[i];
    num[k[i]] = true;
  }
  for (int i = 0; i < n; i++) {
    cin >> K[i];
    num[K[i]] = true;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int tnum = k[i] ^ K[j];
      if (num[tnum]) cnt++;
    }
  }
  if (cnt & 1)
    cout << "Koyomi";
  else
    cout << "Karen";
  return 0;
}
