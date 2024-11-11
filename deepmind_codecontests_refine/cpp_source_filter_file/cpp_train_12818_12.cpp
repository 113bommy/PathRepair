#include <bits/stdc++.h>
using namespace std;
long long int vecerase(long long int a, long long int *v, long long int size,
                       int k, long long int b) {
  long long int cnt = 0;
  long long int tmp = 0;
  if (k == 1) {
    for (int i = 0; i < size; i++) {
      if (v[i] % a == 0) cnt++;
    }
    return cnt;
  }
  if (k == 0) {
    for (int i = 0; i < size; i++) {
      if (v[i] % a == 0 && v[i] % b == 0) cnt++;
    }
    return cnt;
  }
}
int main() {
  long long int n, x, y;
  vector<long long int> v;
  vector<long long int>::iterator it;
  cin >> n >> x >> y;
  long long int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    v.push_back(tmp);
  }
  if (x > y)
    cout << n << endl;
  else {
    sort(v.begin(), v.end());
    it = lower_bound(v.begin(), v.end(), y);
    long long int tmp = it - v.begin();
    if (tmp % 2 != 0)
      cout << (tmp / 2) + 1 << endl;
    else if (tmp % 2 == 0)
      cout << (tmp / 2) << endl;
  }
}
