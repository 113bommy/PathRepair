#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  char str[21];
  cin >> str;
  cout << (26 * (strlen(str) + 1) - strlen(str)) << "\n";
  return 0;
}
