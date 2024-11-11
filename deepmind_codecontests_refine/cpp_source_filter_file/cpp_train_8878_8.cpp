#include <bits/stdc++.h>
using namespace std;
long long a, b;
vector<int> v;
int main() {
  cin >> a >> b;
  for (long long i = a;; i++) {
    long long temp = i;
    while (temp) {
      v.push_back(temp % 10);
      temp /= 10;
    }
    long long num = 0;
    long long len = v.size();
    for (long long j = len - 1; j >= 0; j--)
      if (v[j] == 4 or v[j] == 7) num = (num * 10) + v[j];
    if (num == b) {
      for (int j = len - 1; j >= 0; j--) cout << v[j];
      return 0;
    }
    v.clear();
  }
}
