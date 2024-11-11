#include <bits/stdc++.h>
int main() {
  int N;
  int K;
  std::cin >> N >> K;
  std::string s;
  std::cin >> s;
  int max = 0;
  int count = 0;
  int start = 0;
  for (int i = 0; i < N; i++) {
    while (i < N && count < K) {
      if (s[i] != 'a') count++;
      i++;
    }
    while (i < N && s[i] == 'a') i++;
    max = max > i - start ? max : i - start;
    while (start < N && s[start] == 'a') start++;
    start++;
    count--;
  }
  count = 0;
  start = 0;
  for (int i = 0; i < N; i++) {
    while (i < N && count < K) {
      if (s[i] != 'b') count++;
      i++;
    }
    while (i < N && s[i] == 'b') i++;
    max = max > i - start ? max : i - start;
    while (start < N && s[start] == 'b') start++;
    start++;
    count--;
  }
  std::cout << max << std::endl;
  return 0;
}
