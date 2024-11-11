#include <bits/stdc++.h>
using namespace std;
int n, seq[100001];
int main() {
  cin >> n;
  for (int i = 1; i < n + 1; i++) {
    if (i % 2 == 1)
      seq[i] = i / 2 + 1;
    else
      seq[i] = n - i / 2 + 1;
  }
  for (int i = 1; i < n + 1; i++) cout << seq[i] << " ";
  return 0;
}
