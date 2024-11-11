#include <bits/stdc++.h>
using namespace std;
int N, M;
int val[505];
double mx = -1;
int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> val[i];
  }
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    mx = max(mx, (val[a] + val[b]) / (c + 0.));
  }
  printf("%.15lf", mx);
}
