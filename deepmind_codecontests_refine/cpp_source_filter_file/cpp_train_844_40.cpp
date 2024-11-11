#include <bits/stdc++.h>
using namespace std;
void run() {
  char *str = "abcd";
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cout << str[i % 4] << (i == n - 1 ? "\n" : " ");
}
int main() {
  run();
  return 0;
}
