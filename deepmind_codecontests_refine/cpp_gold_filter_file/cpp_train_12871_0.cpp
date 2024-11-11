#include <bits/stdc++.h>
using namespace std;
int dx[8] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[8] = {-1, 1, 0, 0, 1, -1, 1, -1};
const int SIZE = 450;
int main() {
  int N, M;
  cin >> N >> M;
  int E = 0;
  if (N == 2)
    cout << 103733951 << " " << 103733951 << endl;
  else
    cout << 2 << " " << 103733951 << endl;
  for (int i = N; i >= 3; i--) {
    cout << 1 << " " << i << " " << 2 << endl;
    E++;
  }
  cout << 1 << " " << 2 << " " << 103733951 - E * 2 << endl;
  E++;
  for (int i = 2; i <= N; i++)
    for (int j = i + 1; j <= N; j++) {
      if (E == M) return 0;
      cout << i << " " << j << " " << 999999999 << endl;
      E++;
    }
  return 0;
}
