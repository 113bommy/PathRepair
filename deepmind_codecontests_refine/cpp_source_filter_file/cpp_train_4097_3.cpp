#include <bits/stdc++.h>
using namespace std;
const int maxN = 1000 * 100 + 5;
const int mod = 1000 * 1000 * 1000 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  vector<char> stack;
  for (int i = 1; i < ((int)(s).size()); i++) {
    while (((int)(stack).size()) && s[i] > stack.back()) stack.pop_back();
    stack.push_back(s[i]);
  }
  for (int i = 0; i < ((int)(stack).size()); i++) cout << stack[i];
  cout << endl;
  return 0;
}
