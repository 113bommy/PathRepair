#include <bits/stdc++.h>
using namespace std;
double EPS = 1e-9;
int INF = 2000000000;
long long INFF = 8000000000000000000LL;
double PI = acos(-1);
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};
inline string IntToString(int a) {
  char x[100];
  sprintf(x, "%d", a);
  string s = x;
  return s;
}
inline int StringToInt(string a) {
  char x[100];
  int res;
  strcpy(x, a.c_str());
  sscanf(x, "%d", &res);
  return res;
}
inline string GetString(void) {
  char x[1000005];
  scanf("%s", x);
  string s = x;
  return s;
}
inline string uppercase(string s) {
  int n = (int)s.size();
  for (int(i) = (0); (i) < (n); ++(i))
    if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
  return s;
}
inline string lowercase(string s) {
  int n = (int)s.size();
  for (int(i) = (0); (i) < (n); ++(i))
    if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
  return s;
}
inline void OPEN(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
pair<pair<int, int>, int> data[100005];
int n, m, budget;
pair<int, int> bugs[100005];
priority_queue<pair<int, int> > pq;
int sisa = 0;
int student = 0;
int risan = -1;
int answer[100005];
bool bisa(int x) {
  sisa = 0;
  while (!pq.empty()) pq.pop();
  int L = 0;
  int butuh = 0;
  for (int(i) = (0); (i) < (m); ++(i)) {
    while (L < n && data[L].first.first >= bugs[i].first) {
      pq.push(make_pair(-data[L].first.second, data[L].second));
      ++L;
    }
    if (sisa == 0) {
      if (pq.empty()) return false;
      butuh += -pq.top().first;
      student = pq.top().second;
      pq.pop();
      sisa = x - 1;
      answer[bugs[i].second] = student;
    } else {
      answer[bugs[i].second] = student;
      --sisa;
    }
  }
  return (butuh <= budget);
}
int main() {
  scanf("%d %d %d", &n, &m, &budget);
  for (int(i) = (0); (i) < (m); ++(i)) {
    scanf("%d", &bugs[i].first);
    bugs[i].second = i;
  }
  sort(bugs, bugs + m);
  reverse(bugs, bugs + m);
  for (int(i) = (0); (i) < (n); ++(i)) {
    data[i].second = i;
    scanf("%d", &data[i].first.first);
  }
  for (int(i) = (0); (i) < (n); ++(i)) scanf("%d", &data[i].first.second);
  sort(data, data + n);
  reverse(data, data + n);
  int L = 1;
  int R = m;
  while (L <= R) {
    int M = (L + R) >> 1;
    if (bisa(M)) {
      risan = M;
      R = M - 1;
    } else
      L = M + 1;
  }
  bisa(risan);
  if (risan == -1)
    puts("NO");
  else {
    puts("YES");
    for (int(i) = (0); (i) < (m); ++(i)) printf("%d ", answer[i] + 1);
    puts("");
  }
  return 0;
}
