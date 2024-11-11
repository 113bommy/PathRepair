#include <bits/stdc++.h>
using namespace std;
int Rank[4000010];
int Parent[4000010];
struct DisjointSet {
  int NumberOfComponents;
  DisjointSet() { NumberOfComponents = 0; }
  void Add(int x) {
    if (Rank[x] != -1) return;
    Parent[x] = x;
    Rank[x] = 0;
    ++NumberOfComponents;
  }
  int Find(int x) {
    if (x != Parent[x]) Parent[x] = Find(Parent[x]);
    return Parent[x];
  }
  void Union(int x, int y) {
    int ParentOfX = Find(x);
    int ParentOfY = Find(y);
    if (ParentOfX == ParentOfY) return;
    --NumberOfComponents;
    if (Rank[ParentOfX] > Rank[ParentOfY])
      Parent[ParentOfY] = ParentOfX;
    else
      Parent[ParentOfX] = ParentOfY;
    if (Rank[ParentOfX] == Rank[ParentOfY]) ++Rank[ParentOfY];
  }
};
int n, m;
int Row1(int j) { return j; }
int Col1(int i) {
  if (i == 0) return Row1(0);
  return n - 1 + i;
}
int Row2(int j) {
  if (j == 0) return Col1(m - 1);
  return n - 1 + m - 1 + j;
}
int Col2(int i) {
  if (i == 0) return Row1(n - 1);
  if (i == m - 1) return Row2(n - 1);
  return n - 1 + m - 1 + n - 1 + i;
}
int main() {
  while (cin >> n >> m) {
    if (n == m) {
      cout << n << endl;
      continue;
    }
    if (n > m) swap(n, m);
    memset(Rank, -1, sizeof Rank);
    DisjointSet DS;
    for (int i = (int)(0), _m = (int)(n); i < _m; ++i) {
      DS.Add(Row1(i));
      DS.Add(Row2(i));
    }
    for (int j = (int)(0), _m = (int)(m); j < _m; ++j) {
      DS.Add(Col1(j));
      DS.Add(Col2(j));
    }
    for (int i = (int)(0), _m = (int)(n); i < _m; ++i) {
      if (i != 0) {
        DS.Union(Row1(i), Col1(i));
        DS.Union(Row1(n - i - 1), Col2(i));
        DS.Union(Row2(i), Col1(m - i - 1));
        DS.Union(Row2(n - i - 1), Col2(m - i - 1));
      }
    }
    for (int i = (int)(1), _m = (int)(m - 1); i < _m; ++i)
      if (i > n - 1) {
        DS.Union(Col1(i), Col2(i - (n - 1)));
        DS.Union(Col2(i), Col1(i - (n - 1)));
      }
    cout << DS.NumberOfComponents << endl;
  }
}
