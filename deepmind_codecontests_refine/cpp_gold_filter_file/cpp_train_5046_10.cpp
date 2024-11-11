#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int trp_add[n + 1], trp_xor[n + 1];
  queue<int> q;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> trp_add[i] >> trp_xor[i];
    sum += trp_add[i];
    if (trp_add[i] == 1) q.push(i);
  }
  cout << sum / 2 << endl;
  while (!q.empty()) {
    int rt = q.front();
    q.pop();
    if (trp_add[rt] == 0) continue;
    int tr = trp_xor[rt];
    trp_add[tr]--;
    if (trp_add[tr] == 1) q.push(tr);
    trp_xor[tr] ^= rt;
    cout << rt << " " << tr << endl;
  }
}
