#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(NULL);
  long long n, i, k, j;
  long long *input = NULL;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> k;
    input = (long long *)realloc(input, sizeof(long long) * k);
    for (j = 0; j < k; j++) {
      cin >> *(input + j);
    }
    bool can = false;
    for (j = 0; j < k - 1; j++) {
      if (*(input + i) < *(input + i + 1)) {
        can = true;
        break;
      }
    }
    if (can)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
