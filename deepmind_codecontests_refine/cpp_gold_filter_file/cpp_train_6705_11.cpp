#include <bits/stdc++.h>
using namespace std;
const int blockSize = 400;
int n, m, q;
vector<int> s[110001];
long long a[101001];
long long res[110001];
int met[110001];
int cross[110101][501];
long long add[110001], ans[110010];
vector<int> nums;
void plu(int k, long long x) {
  if (s[k].size() <= blockSize) {
    for (int j = 0; j < s[k].size(); ++j) a[s[k][j]] += x;
    for (int j = 0; j < nums.size(); ++j) ans[nums[j]] += x * cross[k][j];
  } else
    add[k] += x;
}
long long ask(int k) {
  if (s[k].size() > blockSize) {
    long long answer = 0;
    answer += ans[k] + res[k];
    for (int i = 0; i < nums.size(); ++i) answer += add[nums[i]] * cross[k][i];
    return answer;
  } else {
    long long answer = 0;
    for (int i = 0; i < s[k].size(); ++i) answer += a[s[k][i]];
    for (int i = 0; i < nums.size(); ++i) answer += add[nums[i]] * cross[k][i];
    return answer;
  }
}
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) {
    int size;
    cin >> size;
    for (int j = 0; j < size; ++j) {
      long long x;
      cin >> x;
      s[i].push_back(x);
      res[i] += a[x];
    }
    if (size > blockSize) nums.push_back(i);
  }
  for (int i = 0; i < nums.size(); ++i) {
    int num = nums[i];
    for (int j = 0; j < s[num].size(); ++j) met[s[num][j]] = i + 1;
    for (int k = 1; k <= m; ++k)
      for (int j = 0; j < s[k].size(); ++j)
        if (met[s[k][j]] == i + 1) ++cross[k][i];
  }
  for (int it = 0; it < q; ++it) {
    char sim;
    cin >> sim;
    if (sim == '+') {
      int k;
      long long x;
      cin >> k >> x;
      plu(k, x);
    } else {
      int k;
      cin >> k;
      cout << ask(k) << endl;
    }
  }
  return 0;
}
