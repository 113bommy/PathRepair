#include <bits/stdc++.h>
using namespace std;
const int Nmax = 1001;
const int Mmax = 101;
int order;
int N, M;
vector<pair<int, int> > v;
int A[Nmax][Mmax];
void solve_ascending() {
  for (int i = 1; i <= N; ++i) {
    for (int k = 0; k < v.size(); ++k) {
      int st = v[k].first;
      int dr = v[k].second;
      if (A[i][st] > A[i][dr]) swap(A[i][st], A[i][dr]);
    }
    for (int j = 1; j <= M; ++j) {
      int minim = 1e9;
      ;
      int pos = 0;
      for (int k = j + 1; k <= M; ++k) {
        if (A[i][k] < minim) {
          minim = A[i][k];
          pos = k;
        }
      }
      if (pos && A[i][j] > A[i][pos]) {
        swap(A[i][j], A[i][pos]);
        v.push_back(make_pair(j, pos));
      }
    }
  }
}
void solve_descending() {
  for (int i = 1; i <= N; ++i) {
    for (int k = 0; k < v.size(); ++k) {
      int st = v[k].first;
      int dr = v[k].second;
      if (A[i][st] > A[i][dr]) swap(A[i][st], A[i][dr]);
    }
    for (int j = 1; j <= M; ++j) {
      int maxim = 0;
      int pos = 0;
      for (int k = j + 1; k <= M; ++k) {
        if (A[i][k] > maxim) {
          maxim = A[i][k];
          pos = k;
        }
      }
      if (pos && A[i][j] < A[i][pos]) {
        swap(A[i][j], A[i][pos]);
        v.push_back(make_pair(pos, j));
      }
    }
  }
}
int main() {
  cin >> N >> M >> order;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      cin >> A[i][j];
    }
  }
  if (order == 0)
    solve_ascending();
  else
    solve_descending();
  cout << v.size() << "\n";
  if (v.size() > M * (M - 1) / 2)
    while (1)
      ;
  for (int i = 0; i < v.size(); ++i)
    cout << v[i].first << " " << v[i].second << endl;
  return 0;
}
