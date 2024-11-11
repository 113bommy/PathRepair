#include <bits/stdc++.h>
using namespace std;
int n, m;
char F[51][51];
const int N = 7;
int A[5000001];
bool arr[N];
vector<int> P;
int main() {
  memset(arr, true, sizeof(arr));
  for (int i = 2; i < N; i++) {
    if (!A[i]) {
      P.push_back(i);
      for (int j = 1; j * i < N; j++)
        for (int k = i * j; k % i == 0; k /= i) {
          A[k] = A[k / i] + 1;
        }
    }
  }
  for (int i = 3; i < N; i++) {
    A[i] = A[i] + A[i - 1];
  }
  int t, a, b;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d %d", &a, &b);
    printf("%d\n", A[a] - A[b]);
  }
  return 0;
}
