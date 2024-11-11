#include <bits/stdc++.h>
using namespace std;
int N, K;
int number = 0;
int a[2005], b[2005];
void search(int place, int n, int last[]) {
  if (n == N - 1) {
    for (int i = place; i < K; i++)
      if ((b[n] - b[n - 1]) == (a[i] - a[last[n]])) number++;
  } else {
    int end = K - N + n;
    for (int i = place; i <= end; i++) {
      if (n == 0) {
        last[n + 1] = i;
        search(i + 1, n + 1, last);
      } else {
        if ((b[n] - b[n - 1]) == (a[i] - a[last[n]])) {
          last[n + 1] = i;
          search(i + 1, n + 1, last);
        }
      }
    }
  }
}
int main() {
  int last[2005];
  cin >> K >> N;
  for (int i = 0; i < K; i++) {
    cin >> a[i];
    if (i == 0)
      a[i] = a[i];
    else
      a[i] += a[i - 1];
  }
  for (int i = 0; i < N; i++) cin >> b[i];
  sort(a, a + K);
  K = unique(a, a + K) - a;
  if (N == 1) {
    cout << K << endl;
    return 0;
  }
  sort(b, b + N);
  search(0, 0, last);
  cout << number << endl;
  return 0;
}
