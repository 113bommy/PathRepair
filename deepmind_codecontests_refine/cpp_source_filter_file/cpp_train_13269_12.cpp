#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 20;
int n, a;
int arr[N];
vector<vector<int> > ve(N);
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a);
    ve[a].push_back(i);
  }
  for (int i = 2; i < N; ++i)
    if (ve[i].size() > ve[1].size()) return printf("-1"), 0;
  bool sto = false;
  for (int i = 1; i < N; ++i) {
    if (ve[i].size() == 0) sto = true;
    if (ve[i].size() > 0) {
      if (sto) return printf("-1"), 0;
    }
  }
  printf("%d\n", ve[1].size());
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < ve[i].size(); ++j) {
      arr[ve[i][j]] = j + 1;
    }
  }
  for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
  return 0;
}
