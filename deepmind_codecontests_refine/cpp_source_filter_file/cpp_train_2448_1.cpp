#include <bits/stdc++.h>
using namespace std;
int one[2000005];
int zero[2000005];
int main() {
  string a, b;
  cin >> a;
  cin >> b;
  for (int i = 0; i < b.size(); i++) {
    if (b[i] == '1') {
      one[i + 1] = one[i] + 1;
      zero[i + 1] = zero[i];
    } else {
      zero[i + 1] = zero[i] + 1;
      one[i + 1] = one[i];
    }
  }
  int cnt = 0;
  for (int i = 1; i <= a.size(); i++) {
    if (a[i - 1] == '1') {
      cnt += zero[b.size() - a.size() + i] - zero[i - 1];
    } else {
      cnt += one[b.size() - a.size() + i] - one[i - 1];
    }
  }
  cout << cnt << endl;
}
