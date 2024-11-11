#include <bits/stdc++.h>
using namespace std;
int N, Q;
signed long long step;
vector<int> create_factorial(int len, signed long long id) {
  vector<int> ret, cand;
  vector<signed long long> fact(1, 1);
  int i;
  for (i = 0; i < (len); i++) {
    cand.push_back(i);
    fact.push_back(fact.back() * (i + 1));
  }
  for (i = 0; i < (len); i++) {
    int num = id / fact[len - 1 - i];
    id %= fact[len - 1 - i];
    ret.push_back(cand[num]);
    cand.erase(cand.begin() + num);
  }
  return ret;
}
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> N >> Q;
  auto cur = create_factorial(min(N, 15), 0);
  while (Q--) {
    cin >> i;
    if (i == 1) {
      cur = create_factorial(min(N, 15), step);
      int L, R;
      cin >> L >> R;
      signed long long sum = 0;
      if (N <= 15) {
        for (i = L - 1; i <= R - 1; i++) sum += cur[i] + 1;
      } else {
        while (R > N - 15 && L <= R) {
          sum += cur[R - (N - 14)] + (N - 14);
          R--;
        }
        sum += (L + R) * (R - L + 1) / 2;
      }
      cout << sum << endl;
    } else {
      cin >> x;
      step += x;
    }
  }
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  cout.tie(0);
  solve();
  return 0;
}
