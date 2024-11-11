#include <bits/stdc++.h>
using namespace std;
vector<int> prime;
void seive() {
  bool vis[1005 + 5] = {false};
  for (int i = 4; i <= 1005; i = i + 2) vis[i] = true;
  for (int i = 3; i * i <= 1005; i = i + 2) {
    if (vis[i] == false) {
      for (int k = i * i; k <= 1005; k = k + i + i) vis[k] = true;
    }
  }
  for (int i = 2; i < 1005; i++) {
    if (!vis[i]) prime.push_back(i);
  }
}
int main() {
  seive();
  int cases;
  cin >> cases;
  int pos[1005];
  for (int i = 0; i < cases; i++) {
    memset(pos, -1, sizeof(pos));
    int counter = 1;
    int n;
    cin >> n;
    int color[n + 5];
    for (int k = 0; k < n; k++) {
      int now;
      cin >> now;
      for (int j = 0; j < 11; j++) {
        if (now % prime[j] == 0) {
          if (pos[prime[j]] == -1) {
            color[k] = counter;
            pos[prime[j]] = counter;
            counter++;
          } else {
            color[k] = pos[prime[j]];
          }
          break;
        }
      }
    }
    cout << counter << "\n";
    for (int k = 0; k < n; k++) {
      cout << color[k] << " ";
    }
    cout << "\n";
  }
}
