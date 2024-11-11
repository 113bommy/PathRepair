#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const int N = (int)(2e5 + 20);
const int L = 21;
const long long int M = 1000000007;
const double E = 1e-7;
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  cout << "+------------------------+" << '\n';
  cout << "|";
  int r = (n == 0 ? 0 : (n == 1 ? 1 : (n + 1) / 3));
  for (int i = 0; i < r; ++i) cout << "O.";
  for (int i = 0; i < 11 - r; ++i) cout << "#.";
  cout << "|D|)" << '\n';
  r = (n < 2 ? 0 : (n == 2 ? 1 : (n) / 3));
  cout << "|";
  for (int i = 0; i < r; ++i) cout << "O.";
  for (int i = 0; i < 11 - r; ++i) cout << "#.";
  cout << "|.|" << '\n';
  if (n > 2)
    cout << "|O.......................|";
  else
    cout << "|........................|";
  cout << '\n';
  r = (n < 4 ? 0 : (n == 4 ? 1 : (n - 1) / 3));
  cout << "|";
  for (int i = 0; i < r; ++i) cout << "O.";
  for (int i = 0; i < 11 - r; ++i) cout << "#.";
  cout << "|.|" << '\n';
  cout << "+------------------------+" << '\n';
  return 0;
}
