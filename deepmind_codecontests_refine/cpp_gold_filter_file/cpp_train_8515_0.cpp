#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  string S;
  cin >> N >> K >> S;

  vector<int> V;
  S += '/';
  for (int i = 0, cnt = 1; i + 1 < S.size(); i++) {
    if (S.at(i) == S.at(i + 1)) cnt++;
    else {
      V.push_back(cnt);
      cnt = 1;
    }
  }
  if (S.front() != '1') V.insert(V.begin(), 0);

  N = V.size();
  vector<int> C(N + 1);
  for (int i = 1, sum = 0; i < N + 1; i++) {
    C.at(i) = sum += V.at(i - 1);
  }

  int mx = 0;
  for (int i = 0; i < N + 1; i += 2) {
    mx = max(mx, C.at(min(i + K * 2 + 1, N)) - C.at(i));
  }
  cout << mx << "\n";
}