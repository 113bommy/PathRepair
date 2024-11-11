#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> hlt(n);
    vector<long long> dmg(n);
    for (int i = 0; i < n; i++) {
      cin >> hlt[i] >> dmg[i];
    }
    long long bullets = 0;
    long long dmg_needed_first = 9987654321;
    for (int i = 0; i < n; i++) {
      int pi = ((i - 1) + n) % n;
      long long dmg_taken = min(hlt[i], dmg[pi]);
      bullets += hlt[i] - dmg_taken;
      dmg_needed_first = min(dmg_needed_first, dmg_taken);
    }
    bullets += dmg_needed_first;
    cout << bullets << "\n";
  }
}
