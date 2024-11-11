#include <bits/stdc++.h>
using namespace std;
int main() {
  string in;
  while (cin >> in) {
    int n = in.size();
    int kmp[1000000 + 1];
    kmp[0] = -1;
    int j = -1, i = 0;
    while (i < n) {
      while (j >= 0 && in[i] != in[j]) j = kmp[j];
      i++;
      j++;
      kmp[i] = j;
    }
    j = kmp[n];
    int k = n;
    bool solved = false;
    while (j > 0 && !solved) {
      for (int i = 1; i <= n - j; i++)
        if (kmp[i] == j) {
          for (int u = 0; u < j; u++) cout << in[u];
          cout << endl;
          solved = true;
          break;
        }
      j = kmp[j];
    }
    if (!solved) cout << "Just a Legend" << endl;
  }
  return 0;
}
