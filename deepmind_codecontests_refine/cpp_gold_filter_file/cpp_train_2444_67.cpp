#include <bits/stdc++.h>
using namespace std;
bool sortbyfir(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.second == b.second) return a.first < b.first;
  return (a.second < b.second);
}
bool sr(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first == b.first)
    return a.second > b.second;
  else
    return a.first < b.first;
}
bool compmx(int a, int b) { return (a < b); }
long long int binaryToDecimal(string n) {
  string num = n;
  long long int dec_value = 0;
  long long int base = 1;
  for (int i = num.length() - 1; i >= 0; i--) {
    if (num[i] == '1') dec_value += base;
    base = base * 2;
  }
  return dec_value;
}
string decimalToBinary(long long int n) {
  string s = bitset<64>(n).to_string();
  const auto loc1 = s.find('1');
  if (loc1 != string::npos) return s.substr(loc1);
  return "0";
}
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b)) * b;
}
bool is_prime(long long int x) {
  if (x == 1) return false;
  if (x == 2 || x == 3) return true;
  for (long long int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}
bool isp(string str) {
  int l = 0, h = str.length() - 1;
  while (h > l)
    if (str[l++] != str[h--]) return false;
  return true;
}
long long int power(long long int a, long long int b) {
  long long int res = 1ll;
  while (b > 0) {
    if (b % 2ll) res = (res * a) % 1000000007;
    ;
    a = (a * a) % 1000000007;
    ;
    b /= 2ll;
  }
  return res;
}
long long int interact(long long int i) {
  cout << i << "\n";
  cout.flush();
  long long int ret;
  cin >> ret;
  cout.flush();
  return ret;
}
vector<long long int> primes;
void getPrimes() {
  vector<bool> p(1001, true);
  for (long long int i = 2; i * i <= 1000; i++) {
    if (p[i]) {
      for (long long int j = i * i; j <= 1000; j += i) {
        p[j] = false;
      }
    }
  }
  for (long long int i = 2; i <= 1000; i++) {
    if (p[i]) {
      primes.push_back(i);
    }
  }
}
long long int dx[] = {-1, 0, 1, 0};
long long int dy[] = {0, -1, 0, 1};
long long int n, m;
char arr[51][51];
long long int vis[51][51];
bool dfs(long long int i, long long int j, long long int pi, long long int pj,
         char colour) {
  if (i >= n || j >= m || i < 0 || j < 0 || (arr[i][j] != colour)) return 0;
  if (vis[i][j]) return 1;
  vis[i][j] = 1;
  for (long long int in = 0; in < 4; in++) {
    if (i + dx[in] >= n || j + dy[in] >= m || i + dx[in] < 0 || j + dy[in] < 0)
      continue;
    if (i + dx[in] == pi and j + dy[in] == pj) continue;
    if (dfs(i + dx[in], j + dy[in], i, j, colour)) return 1;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      cin >> arr[i][j];
      vis[i][j] = 0;
    }
  }
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      if (vis[i][j] == 0) {
        if (dfs(i, j, -1, -1, arr[i][j])) {
          cout << "Yes"
               << "\n";
          return 0;
        }
      }
    }
  }
  cout << "No"
       << "\n";
  return 0;
}
