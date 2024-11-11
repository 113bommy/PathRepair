#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> a;
  vector<int> b;
  vector<int> draw;
  int x, y;
  cin >> x >> y;
  int i;
  int sum1 = 0, sum2 = 0, sum3 = 0;
  for (i = 1; i <= 6; i++) {
    if (abs(x - i) > abs(y - i)) a.push_back(1);
    if (abs(x - i) < abs(y - i)) b.push_back(1);
    if (abs(x - i) == abs(y - i)) draw.push_back(1);
  }
  for (i = 0; i < a.size(); i++) {
    sum1 = sum1 + a[i];
  }
  for (i = 0; i < b.size(); i++) {
    sum2 = sum2 + b[i];
  }
  for (i = 0; i < draw.size(); i++) {
    sum3 = sum3 + draw[i];
  }
  cout << sum2 << " " << sum3 << " " << sum1;
}
