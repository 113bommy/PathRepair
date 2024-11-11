#include <bits/stdc++.h>
using namespace std;
int N;
int s[100006];
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    scanf("%d", &s[i]);
  }
  int cut = 0;
  while (s[cut] <= s[cut + 1] && cut < N - 1) cut++;
  if (cut == N - 1) {
    cout << 0;
    return 0;
  }
  int ok = 1;
  for (int i = cut + 1; i < N - 1; i++) {
    if (s[i] < s[i + 1]) {
      ok = 0;
      break;
    }
  }
  if (ok && s[N - 1] <= s[0]) {
    cout << N - cut - 1;
  } else {
    cout << -1;
  }
  return 0;
}
