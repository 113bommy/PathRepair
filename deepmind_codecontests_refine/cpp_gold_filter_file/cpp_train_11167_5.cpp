#include <bits/stdc++.h>
using namespace std;
const int KMAX = 3e5;
int N, K;
string s;
vector<char> pos[KMAX + 2];
int val[KMAX + 2];
void Test() {
  cin >> N >> K;
  cin >> s;
  for (int i = 0; i < K; i++) pos[i].clear();
  for (int i = 0; i < N; i++) pos[i % K].push_back(s[i]);
  for (int i = 0; i < K; i++) {
    bool zero = false, one = false;
    for (auto it : pos[i])
      if (it == '0')
        zero = true;
      else if (it == '1')
        one = true;
    if (zero && one) {
      cout << "NO\n";
      return;
    }
    if (zero)
      val[i] = 0;
    else if (one)
      val[i] = 1;
    else
      val[i] = 2;
  }
  int zz = 0, uu = 0;
  for (int i = 0; i < K; i++)
    if (val[i] == 0)
      zz++;
    else if (val[i] == 1)
      uu++;
  int morez = K / 2 - zz;
  int moreu = K / 2 - uu;
  if (morez < 0 || moreu < 0) {
    cout << "NO\n";
    return;
  }
  for (int i = 0; i < K; i++)
    if (val[i % K] == 2) {
      if (morez > 0) {
        val[i % K] = 0;
        morez--;
      } else {
        val[i % K] = 1;
        moreu--;
      }
    }
  int z = 0, u = 0;
  for (int i = 0; i < N; i++) {
    if (val[i % K] == 0)
      z++;
    else
      u++;
    if (i >= K) {
      if (val[(i - K) % K] == 0)
        z--;
      else
        u--;
      if (z != u) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) Test();
  return 0;
}
