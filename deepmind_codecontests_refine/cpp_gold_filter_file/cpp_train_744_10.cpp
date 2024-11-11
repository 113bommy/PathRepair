#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> v(N);
    int s = 0;
    for (int i = 0; i < N; i++) {
      cin >> v[i];
      if (v[i] == 1) {
        s = i;
      }
    }
    int j = s, next = (j + 1) % N;
    while (v[j] + 1 == v[next]) {
      j = (j + 1) % N;
      next = (next + 1) % N;
    }
    if (v[j] == N) {
      cout << "YES\n";
      continue;
    }
    j = s, next = (j - 1 + N) % N;
    while (v[j] + 1 == v[next]) {
      j = (j - 1 + N) % N;
      next = (next - 1 + N) % N;
    }
    if (v[j] == N) {
      cout << "YES\n";
      continue;
    }
    cout << "NO\n";
  }
}
