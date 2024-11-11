#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print(T t) {
  cout << t << endl;
}
long long n = 0, t = 0;
long long small = -1e18, big = 1e18;
const long long mod = 1e9 + 7;
map<long long, long long> occ;
void print2dVec(vector<vector<long long>> v) {
  for (int i = 0; i < v.size(); ++i) {
    cout << i << " : ";
    for (int j = 0; j < v[i].size(); ++j) {
      cout << v[i][j] << " ";
    }
    print("");
  }
}
void printSet(set<long long> s) {
  for (auto itr = s.begin(); itr != s.end(); ++itr) {
    cout << *itr << " ";
  }
}
long long factorial(int n) {
  long long ans = 1;
  for (int i = 1; i <= n; ++i) {
    ans *= i;
  }
  return ans;
}
bool isprime(long long p) {
  for (int i = 2; i * i <= p; ++i) {
    if (p % i == 0 && p != i) {
      return false;
    }
  }
  return true;
}
bool sortVec(const vector<long long>& v1, const vector<long long>& v2) {
  return v1[0] < v2[0];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(10);
  ;
  long long m;
  cin >> n >> m;
  vector<long long> a(n);
  for (long long it = 0; it < n; it++) cin >> a[it];
  ;
  if (n > m) {
    print("0");
  } else {
    long long ans = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        ans = (ans * (abs(a[i] - a[j]))) % m;
      }
    }
    print(ans);
  }
  return 0;
}
