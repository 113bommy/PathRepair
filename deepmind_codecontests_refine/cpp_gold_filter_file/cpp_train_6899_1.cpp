#include <bits/stdc++.h>
using namespace std;
void ac();
int main() {
  cin.tie(0);
  cout.tie(0);
  ac();
  return 0;
}
void ac() {
  string s;
  cin >> s;
  int n = s.size();
  cout << "3\nR " << n - 1 << "\nL " << n << "\nL 2";
}
