#include <bits/stdc++.h>
using namespace std;
bool par[200002];
int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    par[i] = (a % 2 == 0);
  }
  vector<bool> state;
  for (int i = 0; i < N; i++) {
    if (!state.empty() && par[i] == state.back()) {
      state.pop_back();
    } else
      state.push_back(par[i]);
  }
  if (state.size() == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
