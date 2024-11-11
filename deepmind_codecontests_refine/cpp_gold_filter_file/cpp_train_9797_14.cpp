#include <bits/stdc++.h>
using namespace std;
vector<int> answer;
int m, M;
int main() {
  int n, k;
  cin >> n >> k;
  m = k + 1;
  M = 2 * k + 1;
  int put = 0;
  bool odd = true;
  if (n <= M) {
    printf("%d\n%d", 1, n / 2 + 1);
    return 0;
  }
  if (n % M == 0) {
    odd = false;
  }
  if (!odd) {
    put = k + 1;
    printf("%d\n", n / M);
    for (int i = 0; i < n / M; i++) {
      printf("%d ", put + i * M);
    }
  } else {
    int s = n / M + 1;
    int left = n - M * (s - 2);
    int a, b;
    for (a = m; a < M; a++) {
      for (b = a; b < M; b++) {
        if (a + b == left) break;
      }
      if (a + b == left) break;
    }
    put = a - k;
    answer.push_back(put);
    for (int i = 1; i <= s - 2; i++) {
      answer.push_back(put + M * i);
    }
    answer.push_back(n - (b - k - 1));
    printf("%d\n", answer.size());
    for (int i = 0; i < answer.size(); i++) {
      printf("%d ", answer[i]);
    }
  }
  return 0;
}
