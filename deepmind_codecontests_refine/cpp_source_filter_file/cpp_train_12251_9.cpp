#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);
  int N;
  cin >> N;
  vector<int> perm(N);
  for (int i = 0; i < N; i++) {
    cin >> perm[i];
    perm[i]--;
  }
  vector<bool> visited(N);
  bool odd = false;
  for (int i = 0; i < N; i++) {
    if (visited[i]) continue;
    int loc = i, len = 0;
    while (!visited[loc]) {
      visited[loc] = true;
      loc = perm[loc];
      len++;
    };
    if ((len & 1) == 0) {
      odd = !odd;
    }
  }
  bool nodd = N & 1;
  if (odd == nodd) {
    cout << "Petr" << endl;
  } else {
    cout << "Alex" << endl;
  }
  return 0;
}
