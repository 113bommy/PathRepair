#include <bits/stdc++.h>
using namespace std;
int PREP = (cin.tie(nullptr), ios::sync_with_stdio(false),
            cout << fixed << setprecision(9), 0);
int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &a : A) cin >> a;
    vector<int> B;
    int temp[2000] = {};
    for (int a : A) temp[a]++;
    set<int> S;
    for (int i = 0; i <= N; i++)
      if (temp[i] == 0) S.insert(i);
    auto ins = [&](int idx, int val) {
      int prev = A[idx];
      temp[prev]--;
      if (temp[prev] == 0) S.insert(prev);
      A[idx] = val;
      temp[val]++;
      B.push_back(idx + 1);
    };
    for (;;) {
      int mex = *S.begin();
      S.erase(S.begin());
      if (mex < N) {
        ins(mex, mex);
      } else if (mex == N) {
        int diff = -1;
        for (int i = 0; i < N; i++) {
          if (A[i] != i) {
            diff = i;
            break;
          }
        }
        if (diff == -1)
          break;
        else
          ins(diff, mex);
      }
    }
    cout << B.size() << '\n';
    for (auto &b : B) cout << b << ' ';
    cout << '\n';
  }
  return 0;
}
