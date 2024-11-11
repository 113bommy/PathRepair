#include <bits/stdc++.h>
int main() {
  char Vowels[] = "AEIOUY";
  char String[101];
  int Max = 1, Current = 1;
  std::cin >> String;
  for (int i = 0; i < (strlen(String) + 1); ++i) {
    if (strchr(Vowels, String[i]) == nullptr)
      ++Current;
    else {
      if (Current > Max) Max = Current;
      Current = 1;
    }
  }
  std::cout << Max;
  return 0;
}
