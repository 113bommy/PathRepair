#include <bits/stdc++.h>
using namespace std;
int N;
int X[3333], Y[3333];
vector<long long> Node;
bitset<3333> Bit[3333];
long long dis(int i, int j) {
  return (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
}
int main() {
  scanf("%d", &N);
  for (int n = 0; n < N; ++n) scanf("%d%d", X + n, Y + n);
  for (int i = 0; i < N; ++i)
    for (int j = i + 1; j < N; ++j)
      Node.push_back((dis(i, j) << 32) | (i << 16) | j);
  sort(Node.begin(), Node.end());
  while (!Node.empty()) {
    int i = Node.back() & 0x7f7f, j = (Node.back() >> 16) & 0x7f7f;
    Bit[i][j] = Bit[j][i] = true;
    if ((Bit[i] & Bit[j]) != 0) break;
    Node.pop_back();
  }
  printf("%.20lf\n", sqrt((double)(Node.back() >> 32)) / 2);
  return 0;
}
