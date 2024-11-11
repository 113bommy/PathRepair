#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int no, k, b, sum = 0, t = 0, discount = 0;
  cin >> no >> k;
  vector<int> v(no);
  vector<int> b4(no);
  for (int i = 0; i < no; i++) {
    cin >> b4[i];
  }
  for (int i = 0; i < no; i++) {
    cin >> b;
    v[i] = b4[i] - b;
    sum = sum + b;
  }
  sort(v.begin(), v.end());
  while ((v[t] <= 0 || k != 0) && t != no - 1) {
    discount = discount + v[t];
    t++;
    if (k != 0) {
      k--;
    }
  }
  cout << sum + discount;
}
