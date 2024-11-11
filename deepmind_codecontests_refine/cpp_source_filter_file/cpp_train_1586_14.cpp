#include <bits/stdc++.h>
using namespace std;
int T, N, M;
vector<int> v1;
vector<bool> vb;
int main() {
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    v1.clear();
    vb.clear();
    bool ans = true;
    cin >> N >> M;
    v1.resize(N + 1);
    vb.resize(N + 1);
    for (int i = 1; i <= N; i++) cin >> v1[i];
    for (int i = 1; i <= M; i++) {
      int tmp;
      cin >> tmp;
      vb[tmp] = true;
    }
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N - i; j++) {
        if (v1[j] > v1[j + 1]) {
          if (!vb[i]) {
            ans = false;
            break;
          }
          int tmp = v1[j];
          v1[j] = v1[j + 1];
          v1[j + 1] = tmp;
        }
      }
      if (ans == false) break;
    }
    if (ans) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
