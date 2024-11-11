#include <bits/stdc++.h>
using namespace std;
long long mod = pow(10, 9) + 7;
long long gcd(long long a, long long b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long sod(long long n) {
  long long ans = 0;
  while (n > 0) {
    ans += n % 10;
    n /= 10;
  }
  return ans;
}
void dfs(vector<vector<long long> >& g, int visited[], int start) {
  visited[start] = 1;
  for (int i = 0; i < g[start].size(); i++) {
    if (visited[g[start][i]] == 0) {
      dfs(g, visited, g[start][i]);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed;
  cout << setprecision(9);
  int n;
  cin >> n;
  int a[n];
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    m[a[i]]++;
  }
  map<int, int>::iterator itr;
  map<int, char> s;
  int t = 0;
  for (itr = m.begin(); itr != m.end(); itr++) {
    if (itr->second == 1) {
      s[itr->first] = 'A' + t;
      t = (t + 1) % 2;
    } else {
      s[itr->first] = 'A';
    }
  }
  string ans = "";
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (s.find(a[i]) != s.end()) {
      if (m[a[i]] == 1) {
        c++;
        ans += s[a[i]];
      } else if (s[a[i]] == 2) {
        ans += s[a[i]];
        s[a[i]] = 65 + (s[a[i]] - 65 + 1) % 2;
      } else
        ans += s[a[i]];
    }
  }
  if (c % 2 == 0) {
    cout << "YES" << endl;
    cout << ans;
  } else {
    int pos = -1;
    for (int i = 0; i < n; i++) {
      if (m[a[i]] > 2) {
        pos = i;
        break;
      }
    }
    if (pos == -1) {
      cout << "NO";
    } else {
      ans[a[pos]] = 'A' + t;
      cout << "YES" << endl;
      cout << ans;
    }
  }
}
