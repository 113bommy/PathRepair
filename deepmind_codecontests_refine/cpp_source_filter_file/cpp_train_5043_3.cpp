#include <bits/stdc++.h>
using namespace std;
int n, m, p, total, belong[222], sum[222], v[222], len[222], to[222][22],
    f[2][222][222][555];
vector<int> record, l, r, st[222], data[1000050];
int Rand() { return (rand() << 15) | rand(); }
int Solve(vector<int> ask) {
  int len = ask.size(), answer, i, j, k, digit, next, news;
  memset(f, 0, sizeof(f));
  for (i = 0; i < m; i++)
    if (sum[belong[i]] <= p) {
      f[0][len - 1][belong[i]][sum[belong[i]]]++;
      if (i <= ask[len - 1]) {
        f[1][len - 1][belong[i]][sum[belong[i]]]++;
      }
    }
  for (i = len - 1; i > 0; i--) {
    for (j = 1; j <= total; j++) {
      for (k = 0; k <= p; k++) {
        if (f[0][i][j][k] > 0) {
          for (digit = 0; digit < m; digit++) {
            next = to[j][digit];
            news = k + sum[next];
            if (news > p) {
              continue;
            }
            f[0][i - 1][next][news] += f[0][i][j][k];
            f[0][i - 1][next][news] %= 1000000007;
            if (digit < ask[i - 1]) {
              f[1][i - 1][next][news] += f[0][i][j][k];
              f[1][i - 1][next][news] %= 1000000007;
            }
          }
        }
        if (f[1][i][j][k] > 0) {
          next = to[j][ask[i - 1]];
          news = k + sum[next];
          if (news <= p) {
            f[1][i - 1][next][news] += f[1][i][j][k];
            f[1][i - 1][next][news] %= 1000000007;
          }
        }
      }
    }
  }
  answer = 0;
  for (i = len - 1; i > 0; i--) {
    for (j = 1; j <= total; j++) {
      for (k = 0; k <= p; k++)
        if (data[j][0] != 0) {
          answer += f[0][i][j][k];
          answer %= 1000000007;
        }
    }
  }
  for (i = 1; i <= total; i++) {
    for (j = 0; j <= p; j++)
      if (data[i][0] != 0) {
        answer += f[1][0][i][j];
        answer %= 1000000007;
      }
  }
  return answer;
}
int main() {
  int i, j, k, digit, temp, ls, rs, answer;
  bool solved;
  srand((unsigned)time(0));
  scanf("%d%d%d", &n, &m, &p);
  scanf("%d", &ls);
  for (i = 1; i <= ls; i++) {
    scanf("%d", &temp);
    l.push_back(temp);
  }
  scanf("%d", &rs);
  for (i = 1; i <= rs; i++) {
    scanf("%d", &temp);
    r.push_back(temp);
  }
  for (i = 1; i <= n; i++) {
    scanf("%d", &len[i]);
    for (j = 1; j <= len[i]; j++) {
      scanf("%d", &temp);
      st[i].push_back(temp);
    }
    scanf("%d", &v[i]);
  }
  total = 0;
  for (i = 0; i < m; i++) {
    total++;
    data[total].push_back(i);
  }
  for (i = 1; i <= n; i++) {
    for (j = 0; j < len[i]; j++) {
      total++;
      for (k = j; k < len[i]; k++) {
        data[total].push_back(st[i][k]);
      }
    }
  }
  sort(data + 1, data + total + 1);
  for (i = j = 1; i < total; i++)
    if (data[i + 1] != data[j]) {
      data[++j] = data[i + 1];
    }
  total = j;
  for (i = 1; i <= total; i++) {
    temp = data[i].size();
    for (j = 1; j <= n; j++)
      if (temp >= len[j]) {
        record.clear();
        for (k = 0; k < len[j]; k++) {
          record.push_back(data[i][k]);
        }
        if (record == st[j]) {
          sum[i] += v[j];
        }
      }
  }
  for (i = 1; i <= total; i++) {
    temp = data[i].size();
    for (digit = 0; digit < m; digit++) {
      record.clear();
      record.push_back(digit);
      for (j = 0; j < temp; j++) {
        record.push_back(data[i][j]);
      }
      while (true) {
        solved = false;
        for (j = 1; j <= total; j++)
          if (record == data[j]) {
            to[i][digit] = j;
            solved = true;
            break;
          }
        if (solved) {
          break;
        }
        record.pop_back();
      }
    }
  }
  for (i = 0; i < m; i++) {
    record.clear();
    record.push_back(i);
    for (j = 1; j <= total; j++)
      if (data[j] == record) {
        belong[i] = j;
        break;
      }
  }
  temp = l.size();
  l[temp - 1]--;
  for (i = temp - 1; i > 0; i--)
    if (l[i] < 0) {
      l[i] += 10;
      l[i - 1]--;
    }
  record.clear();
  for (i = 0; i < temp; i++)
    if (l[i] > 0) {
      break;
    }
  for (; i < temp; i++) {
    record.push_back(l[i]);
  }
  answer = 0;
  if (record.size() > 0) {
    answer -= Solve(record);
  }
  answer += Solve(r);
  printf("%d\n", (answer % 1000000007 + 1000000007) % 1000000007);
  return 0;
}
