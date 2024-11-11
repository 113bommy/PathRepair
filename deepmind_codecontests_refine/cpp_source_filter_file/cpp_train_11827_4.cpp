#include <bits/stdc++.h>
using namespace std;
void Binary(unsigned long long a[], int n, unsigned long long s) {
  unsigned long long lo = 0;
  unsigned long long hi = n - 1;
  unsigned long long res, resS;
  unsigned long long k_required;
  unsigned long long Somme_of_k;
  while (lo <= hi) {
    k_required = lo + (hi - lo) / 2;
    Somme_of_k = 0;
    unsigned long long S[n];
    for (int i = 1; i < n; i++) {
      S[i] = a[i] + (i * k_required);
    }
    sort(S, S + n);
    for (int i = 1; i <= k_required; i++) {
      Somme_of_k += S[i];
    }
    if (Somme_of_k > s) {
      hi = k_required - 1;
    } else {
      res = k_required;
      resS = Somme_of_k;
      lo = k_required + 1;
    }
  }
  cout << res << " " << resS << endl;
}
int main() {
  unsigned long long n, s;
  cin >> n >> s;
  unsigned long long a[n + 1], price[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  Binary(a, n + 1, s);
}
