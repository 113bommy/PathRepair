#include <bits/stdc++.h>
using namespace std;
void fast() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
const long long MOD = 1e9 + 7;
int main() {
  long long n, s;
  cin >> n >> s;
  if (s & n == 0)
    cout << s / n;
  else
    cout << s / n + 1;
  return 0;
}
