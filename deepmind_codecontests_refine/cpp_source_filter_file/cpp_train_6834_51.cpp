#include <bits/stdc++.h>
using std::cin;
using std::cout;
int main(int argc, char const *argv[]) {
  int k;
  cin >> k;
  if (k == 1) {
    cout << "8\n";
    return 0;
  }
  if (k > 36) {
    cout << "-1\n";
    return 0;
  }
  std::string output(k / 2, '8');
  if (k % 2 == 1) output += '0';
  cout << output << '\n';
  return 0;
}
