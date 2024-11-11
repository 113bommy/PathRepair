#include <bits/stdc++.h>
using namespace std;
vector<int> v1;
int status[(100000007 / 32) + 10];
bool check1(int n, int pos) { return (bool)(n & (1 << pos)); }
int set1(int n, int pos) { return n = n | (1 << pos); }
void sieve() {
  int i, j, k;
  k = int(sqrt(100000007));
  for (i = 3; i <= k; i += 2) {
    if (check1(status[i / 32], i % 32) == 0) {
      for (j = i * i; j <= 100000007; j += 2 * i) {
        status[j / 32] = set1(status[j / 32], j % 32);
      }
    }
  }
  v1.push_back(2);
  for (i = 3; i < 100000007; i += 2) {
    if (check1(status[i / 32], i % 32) == 0) v1.push_back(i);
  }
}
vector<long long int> v2;
void factor(long long int k) {
  long long int i, a;
  v2.clear();
  for (i = 0; i < v1.size(); i++) {
    if (k == 1) break;
    a = v1[i];
    while (k % a == 0) {
      if (k == 1) break;
      v2.push_back(a);
      k /= a;
    }
  }
  if (k != 1) v2.push_back(k);
}
int main() {
  sieve();
  long long int a, b, c, d, i, j, k, l, m, n;
  cin >> n;
  factor(n);
  if (v2.size() == 1 || v2.size() == 0) {
    cout << "1" << endl;
    cout << "0" << endl;
    return 0;
  }
  if (v2.size() == 2) {
    cout << "2" << endl;
    return 0;
  }
  cout << "1" << endl;
  cout << v2[0] * v2[1] << endl;
  return 0;
}
