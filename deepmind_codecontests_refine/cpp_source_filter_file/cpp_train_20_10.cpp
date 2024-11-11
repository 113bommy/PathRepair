#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 1000;
pair<long long, long long> p[maxn];
vector<long long> v;
int getpos(long long V) {
  return lower_bound(v.begin(), v.end(), V) - v.begin() + 1;
}
long long C1[2][maxn];
long long C2[2][maxn];
void add(int x, long long K, long long C[][maxn], int flag) {
  while (0 < x && x < maxn) {
    C[0][x] += 1;
    C[1][x] += K;
    if (flag == -1)
      x += (x) & (-x);
    else
      x -= (x) & (-x);
  }
}
pair<long long, long long> getsum(int x, long long C[][maxn], int flag) {
  long long sum = 0;
  int num = 0;
  while (0 < x && x < maxn) {
    num += C[0][x];
    sum += C[1][x];
    if (flag == -1)
      x -= (x) & (-x);
    else
      x += (x) & (-x);
  }
  return pair<long long, long long>(num, sum);
}
int main() {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> p[i].first;
  for (int i = 1; i <= N; i++)
    cin >> p[i].second, v.push_back(abs(p[i].second));
  sort(p + 1, p + 1 + N);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  long long ans = 0;
  long long cnt2 = 0;
  long long cnts2 = 0;
  for (int i = 1; i <= N; i++) {
    if (p[i].second >= 0) {
      pair<long long, long long> s = getsum(getpos(p[i].second), C1, -1);
      ans += p[i].first * s.first - s.second;
      add(getpos(p[i].second), p[i].first, C1, -1);
      ans += p[i].first * cnt2 - cnts2;
    } else {
      pair<long long, long long> s = getsum(getpos(-p[i].second), C2, 1);
      ans += -p[i].first * s.first - s.second;
      add(getpos(-p[i].second), p[i].first, C2, 1);
      cnt2 += 1;
      cnts2 += p[i].first;
    }
  }
  cout << ans << endl;
  return 0;
}
