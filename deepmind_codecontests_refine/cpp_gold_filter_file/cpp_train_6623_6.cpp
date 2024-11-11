#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x, temp, sum = 0;
  cin >> n >> k >> x;
  vector<int> ch;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    ch.push_back(temp);
    if (i < n - k) sum = sum + ch[i];
  }
  sum = sum + k * x;
  cout << sum;
}
