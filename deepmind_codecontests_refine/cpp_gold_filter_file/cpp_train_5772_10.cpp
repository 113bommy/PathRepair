#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int a;
  vector<int> chats[m];
  int noti[n];
  int mes[m];
  for (int i = 0; i < n; i++) {
    noti[i] = 0;
    for (int j = 0; j < m; j++) {
      mes[j] = 0;
      cin >> a;
      if (a == 1) {
        chats[j].push_back(i);
      }
    }
  }
  int b;
  while (k--) {
    cin >> a >> b;
    mes[b - 1]++;
    noti[a - 1]--;
  }
  for (int i = 0; i < m; i++) {
    vector<int>::iterator en = chats[i].end();
    for (vector<int>::iterator it = chats[i].begin(); it != en; it++) {
      noti[*it] += mes[i];
    }
  }
  for (int i = 0; i < n; i++) {
    cout << noti[i] << " ";
  }
  return 0;
}
