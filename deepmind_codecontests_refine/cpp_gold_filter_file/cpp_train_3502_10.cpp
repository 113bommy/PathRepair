#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j;
  cin >> n >> m;
  string name[n], nameip[n], command[m], commandip[m];
  for (i = 0; i < n; i++) {
    cin >> name[i] >> nameip[i];
  }
  for (i = 0; i < m; i++) {
    cin >> command[i] >> commandip[i];
    commandip[i].resize(commandip[i].size() - 1);
  }
  for (i = 0; i < m; i++) {
    cout << command[i] << " " << commandip[i] << "; #";
    for (j = 0; j < n; j++) {
      if (nameip[j] == commandip[i]) cout << name[j] << endl;
    }
  }
}
