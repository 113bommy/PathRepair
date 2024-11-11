#include <bits/stdc++.h>
using namespace std;
vector<int> teams(200000);
int main() {
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> teams[i];
  for (int i = 0; i < N; i++) {
    if (teams[i] == 0) {
      continue;
    }
    if (teams[i] >= 2) {
      teams[i] %= 2;
    }
    if (teams[i] == 1 && i != N - 1) {
      teams[i + 1] -= 1;
      teams[i] -= 1;
    }
    if (teams[i] != 0) {
      cout << "NO"
           << "\n";
      return 0;
    }
  }
  cout << "YES"
       << "\n";
  return 0;
}
