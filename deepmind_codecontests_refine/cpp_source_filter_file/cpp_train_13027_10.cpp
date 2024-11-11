#include <bits/stdc++.h>
using namespace std;
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v) is >> x;
  return is;
}
const int dr[]{-1, -1, 0, 1, 1, 1, 0, -1};
const int dc[]{0, 1, 1, 1, 0, -1, -1, -1};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  pair<long long, long long> vet[200100];
  long long n, sum = 0;
  cin >> n;
  for (int i = 1; i <= 2 * n; ++i) {
    cin >> vet[i].first;
    vet[i].second = i;
  }
  sort(vet + 1, vet + n + 1);
  sum += vet[1].second + vet[2].second - 2;
  for (int i = 1; i <= 2 * (n - 1); i += 2) {
    long long k = abs(vet[i + 2].second - vet[i].second) +
                  abs(vet[i + 3].second - vet[i + 1].second);
    long long u = abs(vet[i + 3].second - vet[i].second) +
                  abs(vet[i + 2].second - vet[i + 1].second);
    sum += min(u, k);
  }
  cout << sum;
  return 0;
}
