#include <bits/stdc++.h>
using namespace std;
long long power_mod(long long num, long long g) {
  if (g == 0) return 1;
  if (g % 2 == 1)
    return (num * power_mod((num * num) % 1000000007, g / 2)) % 1000000007;
  return power_mod((num * num) % 1000000007, g / 2);
}
long long power(long long num, long long g) {
  if (g == 0) return 1;
  if (g % 2 == 1) return (num * power((num * num), g / 2));
  return power((num * num), g / 2);
}
long long a[201], b[201], c[201];
long long d[201][201][201];
long long solve(long long x, long long y, long long z) {
  long long e = 0;
  if (d[x][y][z] > -1) return d[x][y][z];
  long long ans = 0;
  if (x > 0 && y > 0) {
    ans = max(ans, solve(x - 1, y - 1, z) + a[x - 1] * b[y - 1]);
  }
  if (x > 0 && z > 0) {
    ans = max(ans, solve(x - 1, y, z - 1) + a[x - 1] * c[z - 1]);
  }
  if (z > 0 && y > 0) {
    ans = max(ans, solve(x, y - 1, z - 1) + b[y - 1] * c[z - 1]);
  }
  return d[x][y][z] = ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  string s;
  cin >> s;
  vector<pair<long long, long long> > vec, vec1;
  for (long long i = 0; i < n; i++) {
    long long x = 1;
    while (i + 1 < n && s[i] == s[i + 1]) x++, i++;
    if (s[i] == '?')
      vec.push_back(make_pair(x, 2));
    else
      vec.push_back(make_pair(x, s[i] - '0'));
  }
  long long l = vec.size();
  long long x = 0;
  for (long long i = 0; i < l; i++) {
    if (i == 0)
      vec1.push_back(vec[0]);
    else if (i == 1 && vec1[0].second == 2) {
      vec1[0].first += vec[i].first;
      vec1[0].second = vec[i].second;
    } else if (vec[i].second < 2)
      vec1.push_back(vec[i]), x++;
    else {
      if (i + 1 < l && vec[i + 1].second == vec1[x].second) {
        vec1[x].first += vec[i].first + vec[i + 1].first;
        i++;
      } else
        vec1.push_back(vec[i]), x++;
    }
  }
  l = vec1.size();
  if (l > 1 && vec[l - 1].second == 2) {
    vec1[l - 2].first += vec1[l - 1].first;
    vec1.pop_back();
  }
  vec = vec1;
  l = vec1.size();
  if (l == 1) {
    for (long long i = 1; i <= n; i++) {
      cout << n / i << " ";
    }
    cout << endl;
    return 0;
  }
  cout << n;
  for (long long i = 2; i <= n; i++) {
    vec1.clear();
    long long ans = 0;
    l = vec.size();
    long long prev = 0;
    for (long long j = 0; j < l; j++) {
      long long er = vec[j].first;
      if (j > 0 && vec[j - 1].second == 2) er += vec[j - 1].first;
      if (j + 1 < l && vec[j + 1].second == 2) er += vec[j + 1].first;
      if (er >= i) {
        vec1.push_back(vec[j]);
        if (j + 1 < l && vec[j + 1].second == 2) vec1.push_back(vec[j + 1]);
      } else {
        long long rt = vec1.size();
        if (rt > 0 && vec1[rt - 1].second == 2) {
          vec1[rt - 2].first += vec1[rt - 1].first;
          vec1.pop_back();
        }
        if (j + 1 < l && vec[j + 1].second == 2) {
          vec[j + 2].first += vec[j + 1].first;
          vec[j + 1].first = 0;
        }
      }
      if (j + 1 < l && vec[j + 1].second == 2) {
        prev += vec[j + 1].first + vec[j].first;
        ans += prev / i;
        prev = min(prev % i, vec[j + 1].first);
        j++;
      } else {
        prev += vec[j].first;
        ans += prev / i;
        prev = 0;
      }
    }
    cout << " " << ans;
    vec = vec1;
  }
  return 0;
}
