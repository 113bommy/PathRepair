#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int P[N + 1];
vector<int> S;
int n, k, maxPopped;
bool Check() {
  for (int i = 1; i < (int)S.size(); ++i)
    if (S[i] > S[i - 1]) return false;
  return true;
}
void Read() {
  scanf("%d %d", &n, &k);
  int needed = 1;
  S.push_back(n + 1);
  for (int i = 0; i < k; ++i) {
    int p;
    scanf("%d", &p);
    P[i] = p;
    S.push_back(p);
    while (!S.size() > 1 && S.back() == needed) {
      ++needed;
      S.pop_back();
    }
  }
  maxPopped = needed - 1;
}
void Solve() {
  if (!Check()) {
    printf("-1");
    return;
  }
  for (int i = 0; i < k; ++i) printf("%d ", P[i]);
  int last = maxPopped;
  for (int i = (int)S.size() - 1; i >= 0; --i) {
    for (int j = S[i] - 1; j > last; --j) printf("%d ", j);
    last = S[i];
  }
}
int main() {
  Read();
  Solve();
  return 0;
}
