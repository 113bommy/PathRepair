#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
bool isPrime(long long a) {
  int i;
  for (i = 2; i * i <= a; i++) {
    if (a % i == 0) {
      return 0;
    }
  }
  return (a != 1);
}
bool isPalindrom(string s, int l, int r) {
  for (int i = 0; i < (r - l + 1) / 2; i++) {
    if (s[l + i] != s[r - i]) {
      return 0;
    }
  }
  return 1;
}
template <class type1>
type1 gcd(type1 a, type1 b) {
  type1 t;
  while (b) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}
vector<pair<char, char> > res;
string s1, s2;
int used[30];
int gr[30][30];
void dfs(int v) {
  used[v] = 1;
  int i;
  for (i = 0; i < 30; i++) {
    if (gr[v][i] == 1 && used[i] == 0) {
      res.push_back({v + 'a', i + 'a'});
      dfs(i);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, i, j, a, b;
  cin >> n >> s1 >> s2;
  for (i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      gr[s1[i] - 'a'][s2[i] - 'a'] = 1;
      gr[s2[i] - 'a'][s1[i] - 'a'] = 1;
    }
  }
  for (i = 0; i < n; i++) {
    if (used[i] == 0) {
      dfs(i);
    }
  }
  cout << res.size() << "\n";
  for (auto it : res) {
    cout << it.first << " " << it.second << "\n";
  }
  return 0;
}
