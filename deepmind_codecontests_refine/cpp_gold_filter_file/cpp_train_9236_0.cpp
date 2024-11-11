#include <bits/stdc++.h>
using namespace std;
int stop[100], n, xu, yu, num;
double t, S2U, b1, b2, vs, vb, ans = 100000000;
void go(int k) {
  t = stop[k] / vb;
  b1 = stop[k] - xu;
  b1 *= b1;
  b2 = yu * yu;
  S2U = sqrt((b1 + b2));
  t += (S2U / vs);
}
int main() {
  cin >> n >> vb >> vs;
  for (int i = 0; i < n; i++) {
    cin >> stop[i];
  }
  cin >> xu >> yu;
  for (int i = 1; i < n; i++) {
    go(i);
    if (t <= ans) {
      ans = t;
      num = i;
    }
  }
  cout << num + 1 << endl;
  return 0;
}
