#include <bits/stdc++.h>
using namespace std;
int n;
int w[100];
int inc(int i, int j, int ptr) {
  ptr++;
  while (ptr == i || ptr == j) {
    ptr++;
  }
  return ptr;
}
int best(int i, int j) {
  int res = 0;
  int p = inc(i, j, -1), q = inc(i, j, p);
  for (int i = 0; i < n - 1; i++) {
    res += w[q] - w[p];
    p = inc(i, j, q);
    q = inc(i, j, p);
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < 2 * n; i++) {
    cin >> w[i];
  }
  sort(w, w + 2 * n);
  int result = 100000000;
  for (int i = 0; i < 2 * n; i++) {
    for (int j = i + 1; j < 2 * n; j++) {
      result = min(result, best(i, j));
    }
  }
  cout << result;
}
