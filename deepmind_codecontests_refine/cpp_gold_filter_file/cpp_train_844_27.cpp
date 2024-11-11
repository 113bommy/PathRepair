#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  while (n >= 4) {
    cout << "abcd";
    n -= 4;
  }
  if (n == 3) cout << "abc";
  if (n == 2) cout << "ab";
  if (n == 1) cout << "a";
}
