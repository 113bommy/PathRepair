#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, no, A[100001] = {0}, S[100001] = {0};
  vector<int> H;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &no);
    if (no == 1) H.push_back(i);
  }
  for (i = 1; i <= n; i++) {
    scanf("%d", &no);
    if (no != 0) A[i] = no;
    if (S[no] == 0)
      S[no] = 1;
    else
      S[no] = 2;
  }
  int len = H.size(), c, var, index, max = -1;
  for (i = 0; i < len; i++) {
    c = 1;
    var = H[i];
    while (A[var] != 0 && S[A[var]] != 2) {
      c++;
      var = A[var];
    }
    if (c >= max) {
      max = c;
      index = H[i];
    }
  }
  printf("%d\n", max);
  var = index;
  vector<int> B;
  B.push_back(var);
  while (A[var] != 0 && S[A[var]] != 2) {
    B.push_back(A[var]);
    var = A[var];
  }
  int s = B.size();
  for (i = 1; i < s; i++) printf("%d ", B[s - i]);
  printf("%d\n", B[0]);
  return 0;
}
