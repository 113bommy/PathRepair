#include <bits/stdc++.h>
using namespace std;
vector<long long int> val;
long long int Dfs(vector<long long int> v[], long long int u,
                  long long int past) {
  long long int cnt = 1;
  for (long long int i = 0; i < v[u].size(); i++) {
    if (v[u][i] == past) continue;
    cnt += Dfs(v, v[u][i], u);
  }
  val[u] = cnt;
  return cnt;
}
void UndirGraph(vector<long long int> v[], long long int x, long long int y) {
  v[x].push_back(y);
  v[y].push_back(x);
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    for (long long int i = 0; i < n; i++) val.push_back(-1);
    vector<long long int> v[n];
    for (long long int i = 0; i < n - 1; i++) {
      long long int a, b;
      cin >> a >> b;
      a--;
      b--;
      UndirGraph(v, a, b);
    }
    long long int num;
    cin >> num;
    vector<long long int> primes;
    for (long long int i = 0; i < num; i++) {
      long long int hi;
      cin >> hi;
      primes.push_back(hi);
    }
    while (num < n - 1) {
      primes.push_back(1);
      num++;
    }
    sort(primes.begin(), primes.end());
    long long int lolll = Dfs(v, 0, -1);
    vector<long long int> main_val;
    for (long long int i = 0; i < n; i++) {
      if (val[i] == n) continue;
      long long int x;
      x = (n - val[i]) * val[i];
      main_val.push_back(x);
    }
    sort(main_val.begin(), main_val.end());
    long long int lol = 1000000007;
    long long int ans = 0;
    long long int temp_max;
    if (primes.size() >= n - 1)
      temp_max = n - 2;
    else
      temp_max = n - 1;
    for (long long int i = 0; i < temp_max; i++) {
      long long int temp = (main_val[i] % lol) * (primes[i]);
      temp %= lol;
      ans += temp;
    }
    if (primes.size() >= n - 1) {
      long long int k = n - 2;
      long long int temp = 1;
      while (k < primes.size()) {
        temp *= (primes[k]);
        temp %= lol;
        k++;
      }
      ans += (temp * (main_val[n - 2] % lol));
      ans %= lol;
    }
    cout << ans << "\n";
    val.clear();
  }
  return 0;
}
