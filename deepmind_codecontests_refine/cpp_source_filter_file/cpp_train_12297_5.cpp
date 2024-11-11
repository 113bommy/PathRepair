#include <bits/stdc++.h>
using namespace std;
void Suhaib_Sawalha() {
  long double a, b, sum(0);
  cin >> a >> b;
  long long aa = a, bb = b;
  if (aa & 1 && bb & 1)
    sum = ceil((b - a) / 2) - b;
  else if (!(aa & 1) && !(bb & 1))
    sum = ceil((b - a) / 2) * -1 + b;
  else if (aa & 1 && !(bb & 1))
    sum = ceil((b - a) / 2);
  else
    sum = ceil((b - a) / 2) * -1;
  cout << (long long)sum;
}
void Suhaib_Sawalha1() {
  long long t;
  cin >> t;
  while (t--) {
    Suhaib_Sawalha();
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  Suhaib_Sawalha1();
  return 0;
}
