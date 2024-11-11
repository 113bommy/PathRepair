#include <bits/stdc++.h>
using namespace std;
int A[3005], sum;
int main() {
  int N;
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> A[i];
    for (int j = 1; j < i; ++j)
      if (A[j] > A[i]) ++sum;
  }
  printf("%d.000000\n", sum * 2 - (sum & 1));
  return 0;
}
