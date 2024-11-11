#include <bits/stdc++.h>
using namespace std;
enum status { path = 0, cycle = 1 };
bool is_prime(long long n) {
  if (n <= 1) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long sum(long long n) { return (n * (n + 1) / 2); }
long long sum_interval(long long st, long long en) {
  if (st <= 1) return sum(en);
  return (sum(en) - sum(st - 1));
}
bool is_even(int n) { return !(n % 2); }
void swap_two(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}
int sum_except(vector<int> cookies, int indx) {
  int bagsl = cookies.size(), sum_all = 0;
  for (int i = 0; i < bagsl; i++) {
    if (i != indx) sum_all += cookies[i];
  }
  return sum_all;
}
bool is_palindromic(string s) {
  string orgstr = s;
  reverse(s.begin(), s.end());
  string revstr = s;
  return (orgstr == revstr);
}
long long fib(int n) {
  long long res, first = 1, second = 1;
  if (n == 1 || n == 2) return 1;
  for (int i = 3; i < n; i++) {
    res = first + second;
    first = second;
    second = res;
  }
  return res;
}
unsigned long long min_shots(unsigned long long N) {
  int bottle_shots[3] = {5, 10, 15};
  unsigned long long min_nshots = 0;
  int indx = 2;
  while (N > 0 && indx >= 0) {
    if (N >= bottle_shots[indx]) {
      min_nshots += (N / bottle_shots[indx]);
      N %= bottle_shots[indx];
    } else
      indx--;
  }
  return min_nshots;
}
void finpout() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
}
long long nCr(int n, int r) {
  if (r > (n / 2)) r = n - r;
  long long ans = 1;
  for (int i = 1; i < r + 1; i++) {
    ans *= (n - r + i);
    ans /= i;
  }
  return ans;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long count_bin_digits(long long n) {
  long long digits = 0;
  while (n) {
    digits++;
    n /= 2;
  }
  return digits;
}
long long sum_arr(vector<int> vec) {
  int sum = 0, vecs = vec.size();
  for (int i = 0; i < vecs; i++) sum += vec[i];
  return sum;
}
bool isSubSequence(string str1, string str2, int m, int n) {
  if (m == 0) return true;
  if (n == 0) return false;
  if (str1[m - 1] == str2[n - 1])
    return isSubSequence(str1, str2, m - 1, n - 1);
  return isSubSequence(str1, str2, m, n - 1);
}
bool check_sub(string s1, string s2) {
  int c, d, s1ln = s1.length(), s2ln = s2.length();
  c = d = 0;
  while (s1[c] != '\0') {
    while ((s1[c] != s2[d]) && s2[d] != '\0') {
      d++;
    }
    if (s2[d] == '\0') break;
    d++;
    c++;
  }
  if (s1[c] == '\0')
    return 1;
  else
    return 0;
}
pair<int, int> max_element(vector<int> nums) {
  pair<int, int> mx_indx;
  int vln = nums.size();
  mx_indx.first = INT32_MIN;
  for (int i = 0; i < vln; i++) {
    if (nums[i] > mx_indx.first) {
      mx_indx.first = nums[i];
      mx_indx.second = i;
    }
  }
  return mx_indx;
}
double ecdDistance(int x1, int x2, int y1, int y2) {
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
int n, e, m;
vector<vector<int>> adj;
vector<bool> visted;
int freq[26];
int x[101], y[101];
status dfs(int cur_node, int par_node, int &nodes_cnt) {
  if (visted[cur_node]) return cycle;
  visted[cur_node] = true;
  for (auto child_node : adj[cur_node])
    if (child_node != par_node) {
      ++nodes_cnt;
      if (dfs(child_node, cur_node, nodes_cnt) == cycle) return cycle;
    }
  return path;
}
int main() {
  memset(x, 0, sizeof(x));
  memset(y, 0, sizeof(y));
  int a, b, c;
  cin >> n >> m;
  for (int i = 0; i < m && cin >> a >> b >> c; i++) x[b] += c, y[a] += c;
  int res = 0;
  for (int i = 1; i < n + 1; i++)
    if (x[i] < y[i]) res += (y[i] - x[i]);
  printf("%d\n", res);
  return 0;
}
