#include <bits/stdc++.h>
using namespace std;
map<string, string> asoc;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < int(n); i++) {
    string pc, ip;
    cin >> pc >> ip;
    asoc[ip] = pc;
  }
  for (int i = 0; i < int(m); i++) {
    string comm, ip;
    cin >> comm >> ip;
    ip.pop_back();
    cout << comm << ' ' << ip << " #" << asoc[ip] << '\n';
  }
  return 0;
}
