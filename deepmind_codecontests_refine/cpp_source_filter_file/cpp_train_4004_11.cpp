#include <bits/stdc++.h>
using namespace std;
int dec(long long temp) {
  if (temp < 10) return temp;
  return temp % 10 + dec(temp / 10);
}
long long power(long long a, long long n) {
  if (n == 0)
    return 1;
  else
    return a * power(a, n - 1);
}
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  vector<int> result;
  for (int i = 1; i <= 72; i++) {
    long long temp = b * power(i, a) + c;
    if (temp > 0 && dec(temp) == i && temp < 1000000000) {
      result.push_back(temp);
    }
  }
  cout << result.size() << endl;
  if (result.size() > 0) cout << result[0];
  for (int i = 1; i < result.size(); ++i) {
    cout << " " << result[i];
  }
}
