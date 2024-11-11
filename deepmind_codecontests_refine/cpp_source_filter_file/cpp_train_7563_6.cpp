#include <bits/stdc++.h>
using namespace std;
void Genawy() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL), cout.tie(NULL);
}
int main() {
  Genawy();
  long long n;
  cin >> n;
  if (n == 1)
    cout << 0 << endl;
  else if (n % 2)
    cout << n << endl;
  else
    cout << n / 2 << endl;
  return 0;
}
