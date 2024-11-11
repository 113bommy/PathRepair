#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int n, l, k;
int arr[100009];
long long soma[100009];
long long sum;
multiset<int> k_maiores, k_menores;
void adicionar(int ele) {
  k_maiores.insert(ele);
  sum += ele;
  if ((int)k_maiores.size() > k) {
    __typeof(k_maiores.begin()) itr = k_maiores.begin();
    int ini = (*itr);
    k_maiores.erase(itr);
    k_menores.insert(ini);
    sum -= ini;
  }
}
void remover(int ele) {
  if (k_menores.find(ele) != k_menores.end()) {
    k_menores.erase(k_menores.find(ele));
    return;
  }
  k_maiores.erase(k_maiores.find(ele));
  sum -= ele;
  if (!k_menores.empty()) {
    __typeof(k_menores.end()) itr = k_menores.end();
    itr--;
    int ini = (*itr);
    k_menores.erase(ini);
    k_maiores.insert(ini);
    sum += ini;
  }
}
long long solve() {
  for (int i = 0; i < n; i++) {
    soma[i + 1] = soma[i] + arr[i];
  }
  k_maiores.clear();
  k_menores.clear();
  sum = 0;
  long long resp = 0;
  for (int i = 0; i < l; i++) {
    if (arr[i] < 0) {
      adicionar(-arr[i]);
    }
  }
  for (int i = l; i <= n; i++) {
    long long temp = soma[i] - soma[i - l] + 2 * sum;
    resp = max(resp, temp);
    if (i == n) break;
    if (arr[i] < 0) adicionar(-arr[i]);
    if (arr[i - l] < 0) remover(-arr[i - l]);
  }
  return resp;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long resp1, resp2;
  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cin >> k;
  resp1 = solve();
  for (int i = 0; i < n; i++) {
    arr[i] *= -1;
  }
  resp2 = solve();
  cout << max(resp1, resp2) << '\n';
  return 0;
}
