#include <bits/stdc++.h>
using namespace std;
int s, k;
int f[1000005];
vector<int> vec;
int sum = 1, m = 0, t = 1;
void k_bonacci() {
  f[1] = 1;
  int sum = 1;
  for (int i = 2; sum < s; i++) {
    f[i] = sum;
    sum += f[i];
    if (i > k) sum -= f[i - k];
    t++;
  }
}
void solve() {
  int j = t;
  while (s) {
    if (s >= f[j]) {
      s -= f[j];
      vec.push_back(f[j]);
    }
    j--;
  }
  if (vec.size() == 1)
    cout << 2 << endl << 0 << " " << *vec.begin() << endl;
  else {
    cout << vec.size() << endl;
    for (vector<int>::iterator i = vec.begin(); i != vec.end(); i++)
      cout << *i << " ";
    cout << endl;
  }
}
int main() {
  cin >> s >> k;
  k_bonacci();
  solve();
  return 0;
}
