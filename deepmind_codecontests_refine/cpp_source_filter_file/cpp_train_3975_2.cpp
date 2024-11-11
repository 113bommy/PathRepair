#include <bits/stdc++.h>
using namespace std;
struct subject {
  long long lim1, lim2;
  int com, index;
};
int days_num, K, subj_num;
long long dp[51][101][51], big = -100000000;
pair<long long, int> res[51][101][51];
vector<subject> subj;
bool sorting(subject, subject);
long long fun(int day, long long prev, int last_index) {
  if (day == days_num) return 0;
  if (last_index == subj_num) return big;
  if (dp[day][prev][last_index] != -1) return dp[day][prev][last_index];
  dp[day][prev][last_index] = big;
  for (int cur = last_index + 1; cur < subj_num; cur++) {
    if (subj[cur].com > subj[last_index].com)
      for (long long task = subj[cur].lim1; task <= subj[cur].lim2; task++) {
        if (task == (prev + subj[last_index].lim1) * K ||
            task == (prev + subj[last_index].lim1) + K) {
          long long ans = task + fun(day + 1, task - subj[cur].lim1, cur);
          if (ans > dp[day][prev][last_index]) {
            dp[day][prev][last_index] = ans;
            res[day][prev][last_index].first = task - subj[cur].lim1;
            res[day][prev][last_index].second = cur;
          }
        }
      }
  }
  return dp[day][prev][last_index];
}
int main() {
  subject inp;
  cin >> days_num >> subj_num >> K;
  for (int i = 0; i < subj_num; i++) {
    cin >> inp.lim1 >> inp.lim2 >> inp.com;
    inp.index = i + 1;
    subj.push_back(inp);
  }
  sort(subj.begin(), subj.end(), sorting);
  memset(dp, -1, sizeof dp);
  long long result = big;
  pair<long long, int> start;
  for (int i = 0; i <= subj_num - days_num; i++) {
    for (long long j = subj[i].lim1; j <= subj[i].lim2; j++) {
      long long temp = j + fun(1, j - subj[i].lim1, i);
      if (temp > result) {
        result = temp;
        start.first = j - subj[i].lim1;
        start.second = i;
      }
    }
  }
  if (result < 0)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl
         << subj[start.second].index << " "
         << start.first + subj[start.second].lim1 << endl;
    int day = 1, last_subj = start.second;
    long long prev = start.first;
    while (day != days_num) {
      int index = res[day][prev][last_subj].second;
      int tasks = res[day][prev][last_subj].first;
      cout << subj[index].index << " " << tasks + subj[index].lim1 << endl;
      day++;
      prev = tasks;
      last_subj = index;
    }
  }
  return 0;
}
bool sorting(subject n2, subject n1) {
  if (n1.com > n2.com) return 1;
  return 0;
}
