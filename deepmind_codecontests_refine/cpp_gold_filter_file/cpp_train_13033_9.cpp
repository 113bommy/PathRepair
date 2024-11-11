#include <bits/stdc++.h>
using namespace std;
long long int binpow(long long int a, long long int n) {
  if (n == 0) return 1;
  if (n % 2 == 1)
    return (binpow(a, n - 1)) % 1000000007 * (a % 1000000007) % 1000000007;
  else {
    long long int b = (binpow(a, n / 2) % 1000000007);
    return ((b % 1000000007) * (b % 1000000007)) % 1000000007;
  }
}
set<long long int> s;
void find(long long int n, long long int div) {
  if (n == 1) return;
  if (div * div > n) {
    s.insert(n);
    return;
  }
  if (n % div == 0) {
    s.insert(div);
    find(n / div, div);
  } else if (div == 2)
    find(n, div + 1);
  else
    find(n, div + 2);
}
int main() {
  long long int n, x;
  long long int ans = 0;
  cin >> x >> n;
  find(x, 2);
  vector<long long int> kek;
  for (auto now : s) {
    long long int r = 0;
    long long int z = now;
    while (now <= n) {
      r += n / now;
      if (n / now < z) break;
      now = now * z;
    }
    kek.push_back(r);
  }
  vector<long long int> lul;
  for (auto now : s) lul.push_back(now);
  vector<long long int> answer(s.size());
  for (int i = 0; i < s.size(); i++) {
    answer[i] = (binpow(lul[i], kek[i])) % 1000000007;
  }
  long long int an = 1;
  for (int i = 0; i < s.size(); i++)
    an = ((an % 1000000007) * (answer[i] % 1000000007)) % 1000000007;
  cout << an << endl;
  return 0;
}
