#include <bits/stdc++.h>
using namespace std;
int getN(string s) {
  istringstream is(s);
  int answer;
  is >> answer;
  return answer;
}
int main() {
  int n, k;
  cin >> n >> k;
  vector<string> lines(n);
  for (int i = 0; i < n; i++) {
    cin >> lines[i];
  }
  sort(lines.begin(), lines.end());
  vector<int> I(k);
  for (int i = 0; i < k; i++) {
    I[i] = i;
  }
  int answer = 1 << 28;
  do {
    int ma = -1;
    int mi = 1 << 28;
    for (int i = 0; i < n; i++) {
      string next(k, ' ');
      for (int j = 0; j < k; j++) next[I[j]] = lines[i][j];
      int k = getN(next);
      ma = max(ma, k);
      mi = min(mi, k);
    }
    if (ma >= mi) answer = min(answer, ma - mi);
  } while (next_permutation(I.begin(), I.end()));
  cout << answer << endl;
  return 0;
}
