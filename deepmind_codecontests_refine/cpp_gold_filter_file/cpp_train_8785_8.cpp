#include <bits/stdc++.h>
using namespace std;
int main() {
  ifstream in("in.txt");
  int n;
  cin >> n;
  for (int i = 1; i <= n * n / 2; ++i) {
    cout << i << " " << n * n - i + 1 << " ";
  }
  fprintf(stderr,
          "["
          "END"
          "] Time : %.3lf s.\n",
          clock() * 1.0 / CLOCKS_PER_SEC);
  return 0;
}
