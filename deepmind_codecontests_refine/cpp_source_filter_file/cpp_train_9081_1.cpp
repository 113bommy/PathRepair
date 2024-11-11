#include <bits/stdc++.h>
using namespace std;
int N;
vector<signed long long> A, B;
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> N;
  A.resize(N);
  B.resize(N);
  for (i = 0; i < (N); i++) cin >> A[i];
  for (i = 0; i < (N); i++) cin >> B[i];
  if (A == B) {
    cout << "SMALL" << endl;
    cout << "0" << endl;
    cout << endl;
    return;
  }
  if (N >= 3) {
    string S;
    while (A != B) {
      reverse((B.begin()), (B.end()));
      if (A == B) {
        S += "R";
        break;
      }
      reverse((B.begin()), (B.end()));
      for (i = 0; i < (N - 1); i++)
        if (B[i] >= B[i + 1]) break;
      if (i < N - 1) {
        reverse((B.begin()), (B.end()));
        S += "R";
      }
      for (i = 0; i < (N - 1); i++)
        if (B[i] >= B[i + 1]) break;
      if (i < N - 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
      }
      S += "P";
      for (i = N - 1; i >= 1; i--) B[i] -= B[i - 1];
    }
    reverse((S.begin()), (S.end()));
    int R = count((S.begin()), (S.end()), 'R');
    if (R > 200000) {
      cout << "BIG" << endl;
      cout << R << endl;
    } else {
      cout << "SMALL" << endl;
      cout << S.size() << endl;
      cout << S << endl;
    }
    return;
  } else if (N == 2) {
    signed long long np = 0;
    vector<pair<char, signed long long>> S;
    while (A != B) {
      reverse((B.begin()), (B.end()));
      if (A == B) {
        S.push_back({'R', 1});
        break;
      }
      reverse((B.begin()), (B.end()));
      if (B[0] > B[1]) {
        reverse((B.begin()), (B.end()));
        S.push_back({'R', 1});
      }
      if (B[0] == B[1] || B[0] < min(A[0], A[1]) || B[1] < max(A[0], A[1])) {
        cout << "IMPOSSIBLE" << endl;
        return;
      }
      if (B[0] == min(A[0], A[1])) {
        if ((B[1] - max(A[0], A[1])) % B[0] == 0) {
          np += (B[1] - max(A[0], A[1])) / B[0];
          S.push_back({'P', (B[1] - max(A[0], A[1])) / B[0]});
          B[1] = max(A[0], A[1]);
        } else {
          cout << "IMPOSSIBLE" << endl;
          return;
        }
      } else {
        np += B[1] / B[0];
        S.push_back({'P', B[1] / B[0]});
        B[1] %= B[0];
      }
    }
    if (np > 200000) {
      cout << "BIG" << endl;
      cout << np << endl;
    } else {
      string T;
      for (auto& c : S) {
        for (x = 0; x < (c.second); x++) T += c.first;
      }
      reverse((T.begin()), (T.end()));
      cout << "SMALL" << endl;
      cout << T.size() << endl;
      cout << T << endl;
    }
    return;
  }
  cout << "IMPOSSIBLE" << endl;
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
