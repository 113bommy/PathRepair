#include <bits/stdc++.h>
using namespace std;
int n, m, t, t1, t2, t3, t4, f;
void pvi(vector<int>& thinger) {
  for (int q = 0; q < thinger.size(); q++) cout << thinger[q] << ", ";
  cout << "\n";
}
void pvc(vector<char>& thinger) {
  for (int q = 0; q < thinger.size(); q++) cout << thinger[q] << ", ";
  cout << "\n";
}
void pvs(vector<string>& thinger) {
  for (int q = 0; q < thinger.size(); q++) cout << thinger[q] << ", ";
  cout << "\n";
}
void pvb(vector<bool>& thinger) {
  for (int q = 0; q < thinger.size(); q++) cout << thinger[q] << ", ";
  cout << "\n";
}
void pvvi(vector<vector<int> >& t) {
  for (auto q : t) pvi(q);
}
void pvll(vector<long long>& thinger) {
  for (int q = 0; q < thinger.size(); q++) cout << thinger[q] << ", ";
  cout << "\n";
}
void pvpii(vector<pair<int, int> >& thinger) {
  for (auto q : thinger) cout << q.first << " " << q.second << ", ";
  cout << "\n";
}
void pvvll(vector<vector<long long> >& t) {
  for (auto q : t) pvll(q);
}
vector<string> split(string s, char l) {
  vector<string> temp;
  stringstream ss(s);
  string t;
  while (getline(ss, t, l)) {
    temp.push_back(t);
  }
  return temp;
}
int gcf(long long a, long long b) {
  if (b == 0) return a;
  return gcf(b, a % b);
}
int lcm(long long a, long long b) { return (a * b) / gcf(a, b); }
bool isprime(int k) {
  if (k <= 1) return 0;
  if (k == 2) return 1;
  if (k % 2 == 0) return 0;
  for (int i = 3; i * i <= k; i += 2)
    if (k % i == 0) return 0;
  return 1;
}
const long long llmod = 1000000000000000007LL;
const int mod = 1000000007;
int scan_d() {
  int ip = getchar(), ret = 0, flag = 1;
  for (; ip < '0' || ip > '9'; ip = getchar())
    if (ip == '-') {
      flag = -1;
      ip = getchar();
      break;
    }
  for (; ip >= '0' && ip <= '9'; ip = getchar()) ret = ret * 10 + ip - '0';
  return flag * ret;
}
void println_d(int n) {
  if (n < 0) {
    n = -n;
    putchar('-');
  }
  int i = 10;
  char output_buffer[11];
  output_buffer[10] = '\n';
  do {
    output_buffer[--i] = (n % 10) + '0';
    n /= 10;
  } while (n);
  do {
    putchar(output_buffer[i]);
  } while (++i < 11);
}
char board[52][52];
bool visited[52][52];
int curi, curj;
bool found = 0;
void dfs(int i, int j, int looking, int moves) {
  if (i == curi && j == curj & moves >= 4) found = 1;
  if (found || board[i][j] != looking || visited[i][j]) return;
  visited[i][j] = 1;
  dfs(i - 1, j, looking, moves + 1);
  dfs(i, j - 1, looking, moves + 1);
  dfs(i + 1, j, looking, moves + 1);
  dfs(i, j + 1, looking, moves + 1);
  visited[i][j] = 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  string s;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    for (int j = 1; j <= m; j++) board[i][j] = s[j - 1];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      curi = i;
      curj = j;
      dfs(i, j, board[i][j], 0);
    }
  }
  if (found)
    cout << "Yes"
         << "\n";
  else
    cout << "No"
         << "\n";
  return 0;
}
