#include <bits/stdc++.h>
using namespace std;
const int NMAX = 2010;
int N;
char from[NMAX], to[NMAX];
vector<int> answer;
void shift(int k) {
  answer.push_back(k);
  char temp[NMAX];
  for (int i = N - 1; i >= N - k; --i) temp[N - i - 1] = from[i];
  for (int i = N - k - 1; i >= 0; --i) from[i + k] = from[i];
  for (int i = 0; i < k; ++i) from[i] = temp[i];
}
int main() {
  int i, now = 1;
  cin >> N >> from >> to;
  if (from[N - 1] != to[0]) {
    for (i = 0; i < N - 1; ++i) {
      if (from[i] == to[0]) {
        shift(N - i);
        break;
      }
    }
    if (i >= N - 1) goto impossible;
  }
  while (now < N) {
    for (i = 0; i < N - now; ++i) {
      if (from[i] == to[now]) {
        shift(N - 1 - i);
        shift(1);
        shift(N);
        break;
      }
    }
    if (i >= N - now) goto impossible;
    ++now;
  }
  cout << answer.size() << '\n';
  for (int i : answer) cout << i << ' ';
  cout << '\n';
  return 0;
impossible:
  cout << "-1\n";
  return 0;
}
