#include <bits/stdc++.h>
int c, N;
std::string S;
int main() {
  std::cin >> N >> S;
  for (int i = N; i < S.length(); i += N)
    if (S[i - 1] == S[i - 2] && S[i - 2] == S[i - 3]) c++;
  std::cout << c;
}
