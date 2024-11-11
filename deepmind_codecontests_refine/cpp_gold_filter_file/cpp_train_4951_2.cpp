#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;
int N;
void enter() { cin >> N; }
void process() {
  for (int i = 0; i <= N - 1; i++) {
    for (int j = 0; j <= N - 1; j++)
      cout << (N - j + i * 2) % N * N + (j + i * 2 + 1) % N + 1 << " ";
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  enter();
  process();
  return 0;
}
