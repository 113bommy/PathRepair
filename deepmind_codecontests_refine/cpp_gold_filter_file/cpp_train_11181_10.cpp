#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long maxi = 1e7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  string s, t;
  cin >> s >> t;
  vector<vector<long long>> cost(27, vector<long long>(27, 0));
  for (long long i = 0; i < 26; i++) {
    for (long long j = 0; j < 26; j++) {
      if (i != j) {
        cost[i][j] = maxi;
      }
    }
  }
  long long n;
  cin >> n;
  char a, b;
  long long c;
  while (n--) {
    cin >> a >> b >> c;
    long long temp_1 = a - 'a';
    long long temp_2 = b - 'a';
    cost[temp_1][temp_2] = min(cost[temp_1][temp_2], c);
  }
  if (s.length() != t.length()) {
    cout << -1 << "\n";
  } else {
    for (long long k = 0; k < 26; k++) {
      for (long long i = 0; i < 26; i++) {
        for (long long j = 0; j < 26; j++) {
          cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
        }
      }
    }
    string res_str = "";
    long long res_cost = 0;
    for (long long i = 0; i < s.length(); i++) {
      long long x = s[i] - 'a';
      long long y = t[i] - 'a';
      long long temp_cost = maxi, temp_char = -1;
      for (long long j = 0; j < 26; j++) {
        long long temp = cost[x][j] + cost[y][j];
        if (temp < temp_cost) {
          temp_cost = temp;
          temp_char = j;
        }
      }
      if (temp_cost >= maxi) {
        cout << -1 << "\n";
        return 0;
      } else {
        res_cost += temp_cost;
        res_str += (temp_char + 'a');
      }
    }
    cout << res_cost << "\n";
    cout << res_str << "\n";
  }
  return 0;
}
