#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x;
  cin >> n >> x;
  long long left = x, angry = 0;
  while (n--) {
    char o;
    long long q;
    scanf(" %c %lld", &o, &q);
    if (o == '-') {
      if (left >= q)
        left -= q;
      else
        angry++;
    } else
      left += q;
  }
  cout << left << " " << angry << endl;
  return 0;
}
