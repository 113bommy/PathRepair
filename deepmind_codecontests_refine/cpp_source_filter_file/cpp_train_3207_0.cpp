#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();

  vector<int> ans(N);

  int = j;
  for (int i = 0; i < N; i++) {
    if (S.at(i) == 'R') j = i;
    else ans.at(j + (i - j) % 2)++;
  }
  for (int i = N - 1; i >= 0; i--) {
    if (S.at(i) == 'L') j = i;
    else ans.at(j - (j - i) % 2)++;
  }

  for (int i = 0; i < N; i++) cout << ans.at(i) << "\n";
}