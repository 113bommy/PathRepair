#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n = 1000;
  cin >> s;
  for (int i = 0; i < s.size() - 2; i++)
    n = min(n, abs(n - stoi(s.substr(i, 3))));
  cout << n << endl;
}
