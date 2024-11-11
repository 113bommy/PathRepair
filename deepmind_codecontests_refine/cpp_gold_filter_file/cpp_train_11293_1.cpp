#include <bits/stdc++.h>
using namespace std;
static char a[100][100];
int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < N; j++) {
      a[j][i] = s.at(j);
    }
  }
  for (int i = 0; i < 2 * N; i++) {
    for (int j = 0; j < 2 * M; j++) {
      cout << a[i / 2][j / 2];
    }
    cout << endl;
  }
}
