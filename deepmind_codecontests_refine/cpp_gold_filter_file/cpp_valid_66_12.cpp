#include <bits/stdc++.h>
using namespace std;
vector<int> arre;
void inicio() {
  int cont = 0;
  int i = 1;
  while (cont < 1000) {
    if (i % 3 && i % 10 != 3) {
      arre.push_back(i);
      cont++;
    }
    i++;
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  inicio();
  int T, x;
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> x;
    cout << arre[x - 1] << "\n";
  }
  return 0;
}
