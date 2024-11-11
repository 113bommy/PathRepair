#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1000010;
pair<string, int> pr[Maxn];
int N;
bool bo[Maxn];
int num[Maxn];
set<int> S1, S0;
priority_queue<pair<int, int> > A, B;
int bit[Maxn];
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= 9; i++) bit[i] = 1;
  for (int i = 10; i <= 1000000; i++) bit[i] = bit[i / 10] + 1;
  int c1 = 0, c0 = 0;
  for (int i = 1; i <= N; i++) cin >> pr[i].first >> pr[i].second;
  for (int i = 1; i <= N; i++) {
    int p = 0;
    bool bk = true;
    if (pr[i].second)
      c1++;
    else
      c0++;
    for (int j = 0; j < pr[i].first.length(); j++) {
      if (pr[i].first[j] >= '0' && pr[i].first[j] <= '9')
        p = p * 10 + pr[i].first[j] - '0';
      else
        bk = false;
    }
    if (bk && pr[i].first.length() == bit[p]) {
      if (p <= N) bo[p] = 1;
      num[i] = p;
    }
  }
  for (int i = 1; i <= N; i++) {
    if (num[i] == 0) {
      if (pr[i].second == 0)
        B.push(make_pair(0, i));
      else
        A.push(make_pair(0, i));
    } else if (pr[i].second == 1 && num[i] > c1)
      A.push(make_pair(1, i));
    else if (pr[i].second == 0 && num[i] <= c1)
      B.push(make_pair(1, i));
  }
  for (int i = 1; i <= N; i++)
    if (!bo[i]) {
      if (i <= c1)
        S1.insert(i);
      else
        S0.insert(i);
    }
  bool bk = 1;
  for (int i = 1; i <= N; i++) bk &= bo[i];
  int ss = A.size() + B.size();
  int p;
  if (bk) {
    ss++;
    if (A.size() == 0 && B.size() == 0) {
      printf("0\n");
      return 0;
    } else
      printf("%d\n", ss);
    pair<int, int> x;
    if (A.size())
      x = A.top();
    else if (B.size())
      x = B.top();
    if (num[x.second] <= c1)
      S1.insert(num[x.second]);
    else
      S0.insert(num[x.second]);
    printf("move ");
    cout << pr[x.second].first << " " << N + 1 << endl;
    string kk;
    for (int i = (1e7); i >= 1; i /= 10) {
      if (N + 1 >= i) kk.push_back('0' + (N + 1) / i % 10);
    }
    pr[x.second].first = kk;
    num[x.second] = 0;
    if (x == A.top()) A.pop(), A.push(make_pair(0, x.second));
    if (x == B.top()) B.pop(), B.push(make_pair(0, x.second));
  } else
    printf("%d\n", ss);
  while (A.size() || B.size()) {
    while (A.size()) {
      pair<int, int> x = A.top();
      if (!S1.empty()) {
        printf("move ");
        cout << pr[A.top().second].first << " " << (*S1.begin()) << endl;
        if (num[A.top().second] <= N && num[A.top().second] != 0)
          S0.insert(num[A.top().second]);
        S1.erase(S1.begin());
        A.pop();
      } else
        break;
    }
    while (B.size()) {
      pair<int, int> x = B.top();
      if (!S0.empty()) {
        printf("move ");
        cout << pr[B.top().second].first << " " << (*S0.begin()) << endl;
        if (num[B.top().second] <= N && num[B.top().second] != 0)
          S1.insert(num[B.top().second]);
        S0.erase(S0.begin());
        B.pop();
      } else
        break;
    }
  }
  return 0;
}
