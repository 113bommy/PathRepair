#include <bits/stdc++.h>
using namespace std;
int ara[100005];
int main() {
  int a, diff;
  cin >> a >> diff;
  for (int i = 0; i < a; i++) cin >> ara[i];
  long long i, j, sum = 0;
  i = 0, j = 2;
  while (j < a) {
    while (ara[j] - ara[i] > diff) i++;
    sum += ((j - i) * (j - i - 1)) / 2;
    j++;
  }
  cout << sum << endl;
}
