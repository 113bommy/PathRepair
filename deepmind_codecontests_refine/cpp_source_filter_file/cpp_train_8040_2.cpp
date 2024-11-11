#include <bits/stdc++.h>
using namespace std;
int T, N;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  while (T--) {
    cin >> N;
    set<long long> m;
    for (int i = 0; i < N; i++) {
      int v;
      cin >> v;
      long long next = (i + v + N) % N;
      m.insert(next);
    }
    if (m.size() != N)
      cout << "NO"
           << "\n";
    else
      cout << "YES"
           << "\n";
  }
}
