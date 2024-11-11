#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, m, i, j, min_s = INT_MAX, k, temp;
  vector<int> v, t;
  string S, T;
  cin >> n >> m;
  cin >> S >> T;
  for (i = 0; i < m - n + 1; i++) {
    k = i;
    temp = 0;
    for (j = 0; j < n; j++) {
      if (S[j] != T[i++]) {
        temp++;
        t.push_back(i);
      }
    }
    i = ++k;
    if (temp < min_s) {
      min_s = temp;
      v.clear();
      for (vector<int>::iterator it = t.begin(); it != t.end(); it++)
        v.push_back(*it);
    }
    t.clear();
  }
  printf("%d\n", min_s);
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    printf("%d ", *it);
}
