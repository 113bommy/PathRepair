#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const unsigned gen_seed =
    std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);
const int A = 420000;
long long a[A];
void amul(int k) {
  for (int i = A - 1; i >= 0; i--) {
    a[i] = -a[i];
    if (i >= k) a[i] += a[i - k];
  }
}
bool adiv(int k) {
  for (int i = 0; i < A; i++) {
    if (a[i] != 0) {
      if (i + k < A) {
        a[i + k] += a[i];
      } else
        return false;
    }
  }
  return true;
}
int main() {
  int n;
  scanf("%d\n", &n);
  string s;
  getline(cin, s);
  for (int i = 0; i < n; i++) a[i] = s[i] - '0';
  int nf = n;
  for (int k = 400; k > 1; k--) {
    while (nf % (k * k) == 0) nf /= k;
  }
  int d = n / nf;
  int l = nf;
  std::vector<int> p;
  for (int i = 2; i < nf + 1; i++) {
    if (l % i == 0) {
      p.push_back(i);
      l /= i;
    }
  }
  std::vector<int> mul;
  std::vector<int> div;
  for (int i = 1; i < nf + 1; i++) {
    if (nf % i == 0) {
      int cnt = 0;
      for (auto pr : p)
        if (i % pr == 0) cnt++;
      if (cnt % 2 == p.size() % 2)
        mul.push_back(i);
      else
        div.push_back(i);
    }
  }
  for (auto x : div) amul(x);
  for (auto x : mul)
    if (!adiv(x)) {
      cout << "NO";
      return 0;
    }
  cout << "YES";
}
