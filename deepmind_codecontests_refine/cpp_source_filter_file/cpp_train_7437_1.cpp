#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, K, P, X;
vector<int> odd, eve, Ans[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> K >> P;
  bool f = 0;
  for (int i = 1; i <= n; i++) {
    cin >> X;
    if (X & 1)
      odd.push_back(X);
    else
      eve.push_back(X);
  }
  if (K > n || odd.size() < K - P) return puts("NO"), 0;
  for (int i = 1; i <= P; i++) {
    if (eve.size()) {
      Ans[i].push_back(eve.back());
      eve.pop_back();
    } else if (odd.size() > 1) {
      Ans[i].push_back(odd.back());
      odd.pop_back();
      Ans[i].push_back(odd.back());
      odd.pop_back();
    } else
      f = 1;
  }
  for (int i = P + 1; i <= K; i++) {
    if (odd.size()) {
      Ans[i].push_back(odd.back());
      odd.pop_back();
    } else
      f = 1;
  }
  f = f || odd.size() % 2;
  if (f) return puts("NO"), 0;
  cout << ("YES\n");
  for (auto x : eve) Ans[1].push_back(x);
  for (auto x : odd) Ans[P + 1].push_back(x);
  for (int i = 1; i <= K; i++) {
    cout << Ans[i].size() << " ";
    for (auto x : Ans[i]) cout << x << " ";
    cout << "\n";
  }
}
