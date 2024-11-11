#include <bits/stdc++.h>
using namespace std;
int visited[10005];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int fd[n + 4];
    for (int i = 1; i <= n; i++) {
      int d;
      cin >> d;
      fd[i] = d;
    }
    if (fd[n] == 0) {
      for (int i = 1; i < n + 2; i++) {
        cout << i << " ";
      }
      cout << endl;
      continue;
    }
    if (fd[1] == 1) {
      cout << n + 1 << " ";
      for (int i = 1; i < n + 1; i++) {
        cout << i << " ";
      }
      cout << endl;
      continue;
    }
    int ans;
    if (fd[1] == 0 && fd[n] == 1) {
      for (int i = 1; i < n + 1; i++) {
        if (fd[i] == 0 && fd[i + 1] == 1) {
          ans = i;
        }
      }
    }
    for (int i = 1; i <= ans; i++) {
      cout << i << " ";
    }
    cout << n + 1 << " ";
    for (int i = ans + 1; i < n + 1; i++) {
      cout << i << " ";
    }
    cout << endl;
  }
}
