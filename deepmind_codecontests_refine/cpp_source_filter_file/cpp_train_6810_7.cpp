#include <bits/stdc++.h>
using namespace std;
int number[10] = {0};
int tryit[6] = {689, 698, 869, 896, 968, 986};
int numbers[] = {1, 6, 8, 9};
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    number[s[i] - '0']++;
  }
  long long x = 0;
  for (int j = 0; j < number[6] - 1; j++) cout << 1, x *= 10, x += 1, x %= 7;
  for (int i = 2; i < 6; i++)
    for (int j = 0; j < number[i]; j++) cout << i, x *= 10, x += i, x %= 7;
  for (int j = 0; j < number[6] - 1; j++) cout << 6, x *= 10, x += 6, x %= 7;
  for (int j = 0; j < number[7]; j++) cout << 7, x *= 10, x += 7, x %= 7;
  for (int i = 8; i < 10; i++)
    for (int j = 0; j < number[i] - 1; j++) cout << i, x *= 10, x += i, x %= 7;
  x *= 10000;
  do {
    int k = 0;
    for (int i = 0; i < 4; i++) k *= 10, k += numbers[i];
    if (!((x + k) % 7)) {
      cout << k << endl;
      break;
    }
  } while (std::next_permutation(numbers, numbers + 4));
  for (int i = 0; i < number[0]; i++) cout << 0;
  return 0;
}
