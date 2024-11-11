#include <bits/stdc++.h>
using namespace std;
ostream &ra(ostream &stream) {
  stream << " ------->";
  return stream;
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    if (n % 10 == 0)
      n = n / 10;
    else
      n--;
  }
  cout << n;
  return 0;
}
