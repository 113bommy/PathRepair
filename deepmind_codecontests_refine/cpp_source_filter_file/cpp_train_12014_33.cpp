#include <bits/stdc++.h>
using namespace std;
bool mark[20000000];
int main(int argc, char *argv[]) {
  int n, c = 0;
  cin >> n;
  for (int i = 2; i <= 1000000; i++) {
    if (!mark[i])
      for (int j = 2 * i; j <= 1000000; j += i) mark[j] = 1;
  }
  for (int i = 1; i <= 10000000; i++) {
    if (c == n) break;
    if (!mark[i]) {
      cout << i << " ";
      c++;
    }
  }
  return EXIT_SUCCESS;
}
