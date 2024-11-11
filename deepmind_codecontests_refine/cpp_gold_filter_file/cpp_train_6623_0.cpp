#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main() {
  int n, k, x;
  vector<int> chores;
  int i;
  int c;
  cin >> n >> k >> x;
  for (i = 0; i < n; i++) {
    cin >> c;
    chores.push_back(c);
  }
  c = 0;
  for (i = n - 1; i >= 0; i--) {
    if (k > 0) {
      c += x;
      k--;
    } else
      c += chores[i];
  }
  cout << c;
  return 0;
}
