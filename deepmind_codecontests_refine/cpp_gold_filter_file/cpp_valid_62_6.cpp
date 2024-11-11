#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int c = 0; c < N; c++) {
      cin >> v[c];
    }
    if (v[N - 1] == 0) {
      for (int c = 0; c < N + 1; c++) {
        cout << c + 1 << " ";
      }
      cout << "\n";
      continue;
    }
    if (v[0] == 1) {
      cout << N + 1 << " ";
      for (int c = 0; c < N; c++) {
        cout << c + 1 << " ";
      }
      cout << "\n";
      continue;
    }
    int lastBeforeEnd = N - 1;
    while (lastBeforeEnd >= 0) {
      if (v[lastBeforeEnd] == 0) break;
      lastBeforeEnd--;
    }
    for (int c = 0; c < N; c++) {
      cout << c + 1 << " ";
      if (lastBeforeEnd == c) {
        cout << N + 1 << " ";
      }
    }
    cout << "\n";
  }
}
