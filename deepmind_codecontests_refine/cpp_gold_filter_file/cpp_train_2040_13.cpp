#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int i = 1, j = n, count = 0, k = 1;
  while (k <= (n - 1)) {
    count = count + ((i + j) % (n + 1));
    if (k % 2 == 1) {
      i++;
    } else {
      j--;
    }
    k++;
  }
  cout << count;
}
