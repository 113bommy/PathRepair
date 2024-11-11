#include <bits/stdc++.h>
using namespace std;
int v[100001][2];
int c[100001][2], N;
int l[100001];
int main() {
  cin >> N;
  memset(c, 0, sizeof(c));
  memset(l, 0, sizeof(l));
  for (int i = 0; i < N; i++) {
    cin >> v[i][0] >> v[i][1];
    c[i][0] = c[i][1] = N - 1;
    l[v[i][0]]++;
  }
  for (int i = 0; i < N; i++) {
    c[i][0] += l[v[i][1]];
    c[i][1] -= l[v[i][1]];
  }
  for (int i = 0; i < N; i++) {
    cout << c[i][0] << " " << c[i][1] << endl;
  }
  return 0;
}
