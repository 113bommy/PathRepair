#include <bits/stdc++.h>
using namespace std;
int N;
int A[200000];
int main() {
  scanf("%d", &N);
  for (int(i) = 0; (i) < (N); (i)++) scanf("%d", &A[i]);
  long long res = 0;
  int tt = 0;
  for (int(i) = 0; (i) < (N); (i)++)
    if (A[i] == 0) tt++;
  for (int(i) = 0; (i) < (N); (i)++) {
    if (A[i] == 0)
      tt--;
    else
      res += tt;
  }
  cout << res << endl;
}
