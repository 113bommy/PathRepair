#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long> V(n), T(n);
  for (int i = 0; i < n; i++) cin >> V[i];
  for (int i = 0; i < n; i++) cin >> T[i];
  set<long long> A;
  long long t = 0;
  for (int i = 0; i < n; i++) {
    long long melted = 0;
    A.insert(V[i] + t);
    while (!A.empty() && ((*A.begin()) <= t + T[i])) {
      melted += (*A.begin() - t);
      A.erase(A.begin());
    }
    melted += T[i] * A.size();
    t += T[i];
    cout << melted << ' ';
  }
  return 0;
}
