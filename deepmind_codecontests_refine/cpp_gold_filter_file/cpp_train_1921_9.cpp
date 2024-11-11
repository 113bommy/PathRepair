#include <bits/stdc++.h>
using namespace std;
int parent[50];
int anc(int n) {
  while (parent[n] != n) n = parent[n];
  return n;
}
int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++) parent[i] = i;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (anc(a) != anc(b)) {
      parent[anc(b)] = anc(a);
    }
  }
  int rxs = N;
  for (int i = 0; i < N; i++) {
    if (anc(i) == i) rxs--;
  }
  long long result = 1;
  for (int i = 0; i < rxs; i++) result *= 2;
  cout << result << endl;
}
