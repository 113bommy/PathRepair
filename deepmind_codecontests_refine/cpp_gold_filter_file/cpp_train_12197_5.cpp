#include <bits/stdc++.h>
using namespace std;
char c[5][5] = {{'a', 'e', 'i', 'o', 'u'},
                {'e', 'i', 'o', 'u', 'a'},
                {'i', 'o', 'u', 'a', 'e'},
                {'o', 'u', 'a', 'e', 'i'},
                {'u', 'a', 'e', 'i', 'o'}};
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int x = -1, y = -1;
  for (int i = 1; i < n; ++i) {
    if (n % i == 0) {
      if (i > 4 && (n / i) > 4) {
        x = i;
        y = n / i;
      }
    }
  }
  if (x == -1) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < y; ++j) {
      cout << c[i % 5][j % 5];
    }
  }
  cout << endl;
  return 0;
}
