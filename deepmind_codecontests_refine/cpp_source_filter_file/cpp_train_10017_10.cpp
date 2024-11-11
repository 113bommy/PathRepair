#include <bits/stdc++.h>
template <typename T>
bool isOdd(T num) {
  return num % 2 != 0;
}
int main(int argc, char *argv[]) {
  int n;
  std::cin >> n;
  std::vector<char> in;
  char input;
  long long int sum = 0;
  bool oddSum = false;
  int numOfWays = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> input;
    in.push_back(input);
    sum += input;
  }
  oddSum = isOdd(sum);
  for (int i = 0; i < n; i++) {
    if (isOdd(in[i]) && oddSum)
      numOfWays++;
    else if (!isOdd(in[i]) && !oddSum)
      numOfWays++;
  }
  std::cout << numOfWays << std::endl;
  return 0;
}
