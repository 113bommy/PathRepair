#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1 << 8;
int N, M, Parent[MaxN], Size[MaxN];
int FindRoot(int idx) {
  if (Parent[idx] != idx)
    return Parent[idx] = FindRoot(Parent[idx]);
  else
    return idx;
}
inline bool Merge(int idx, int idy) {
  idx = FindRoot(idx), idy = FindRoot(idy);
  if (idx == idy) return false;
  if (Size[idx] > Size[idy])
    Parent[idy] = idx, Size[idy] = 0, Size[idx] += Size[idy];
  else
    Parent[idx] = idy, Size[idx] = 0, Size[idy] += Size[idx];
  return true;
}
int main(void) {
  cin.sync_with_stdio(0);
  cout.sync_with_stdio(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++) Parent[i] = i, Size[i] = 1;
  int Cycles = 0;
  for (int i = 0; i < M; i++) {
    int idx, idy;
    cin >> idx >> idy;
    idx--;
    idy--;
    Cycles += !Merge(idx, idy);
  }
  if (Cycles && N == M)
    cout << "FHTAGN!" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
