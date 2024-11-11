#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  unsigned long long n;
  cin >> n;
  unsigned long long best = 0, bestnum = 0, count = 0;
  for (unsigned long long i = 0; i < n; i++) {
    unsigned long long num;
    cin >> num;
    if (i == 0) {
      bestnum = num;
      best = i;
      continue;
    }
    if (num < bestnum) {
      best = i;
      bestnum = num;
      count = 1;
    } else if (num == bestnum)
      count++;
  }
  if (count == 1)
    cout << best + 1;
  else
    cout << "Still Rozdil";
  return 0;
}
