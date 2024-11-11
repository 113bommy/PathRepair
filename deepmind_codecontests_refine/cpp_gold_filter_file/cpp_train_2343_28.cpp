#include <bits/stdc++.h>
using namespace std;
int table[2000010];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int in;
    scanf("%d", &in);
    table[in]++;
  }
  int c = 0;
  for (int i = 0; i < 2000001; i++) {
    int count = table[i];
    table[i] %= 2;
    c += table[i];
    if (count >= 2) table[i + 1] += (count / 2);
  }
  cout << c << endl;
}
