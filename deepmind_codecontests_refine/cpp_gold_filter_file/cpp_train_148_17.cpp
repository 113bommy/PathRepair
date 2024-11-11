#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, total = 0;
  for (long long i = 0; i < 5; i++) {
    cin >> n;
    total += n;
  }
  if (total % 5 != 0 || total <= 0)
    cout << "-1" << endl;
  else
    cout << total / 5 << endl;
}
