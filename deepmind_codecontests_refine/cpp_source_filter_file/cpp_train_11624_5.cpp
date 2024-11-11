#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int N, K;
  cin >> N >> K;
  if (K == 1) {
    cout << 0 << '\n';
    exit(0);
  }
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }
  string C;
  cin >> C;
  vector<int> reds;
  vector<int> whites;
  vector<int> oranges;
  for (int i = 0; i < N; i++) {
    if (C[i] == 'R') reds.push_back(B[i]);
    if (C[i] == 'W') whites.push_back(B[i]);
    if (C[i] == 'O') oranges.push_back(B[i]);
  }
  sort(reds.begin(), reds.end(), greater<int>());
  sort(whites.begin(), whites.end(), greater<int>());
  sort(oranges.begin(), oranges.end(), greater<int>());
  auto solve = [&](vector<int> a, vector<int> b) -> int {
    int na = int(a.size());
    int nb = int(b.size());
    if (na + nb < K || !na || !nb) {
      return -1;
    }
    auto ast = a.begin();
    auto bst = b.begin();
    int tot = 0;
    for (int z = 0; z < K; z++) {
      if (bst == b.end()) {
        tot += *(ast++);
      } else if (ast == a.end()) {
        tot += *(bst++);
      } else if (*ast > *bst) {
        tot += *(ast++);
      } else {
        tot += *(bst++);
      }
    }
    if (ast == a.begin()) {
      tot -= *(--bst);
      tot += *(ast++);
    } else if (bst == b.begin()) {
      tot -= *(--ast);
      tot += *(bst++);
    }
    return tot;
  };
  cout << max(solve(reds, oranges), solve(whites, oranges)) << '\n';
  return 0;
}
