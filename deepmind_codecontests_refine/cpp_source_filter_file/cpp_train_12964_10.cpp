#include <bits/stdc++.h>
using namespace std;
const int maxn = 150100;
void nie() {
  puts("0");
  exit(0);
}
int N, ar[maxn], is[maxn];
map<pair<int, int>, bool> used;
vector<pair<int, int> > oneof;
vector<int> must;
bool check(int a, int b) {
  if (a == b) return 0;
  if (a > b) swap(a, b);
  if (used[pair<int, int>(a, b)]) return 0;
  swap(ar[a], ar[b]);
  if (a & 1 &&
      ((a != N && ar[a] >= ar[a + 1]) || (a != 1 && ar[a] >= ar[a - 1]))) {
    swap(ar[a], ar[b]);
    return 0;
  }
  if (!(a & 1) && (ar[a] <= ar[a - 1] || ar[a] <= ar[a + 1])) {
    swap(ar[a], ar[b]);
    return 0;
  }
  if (b & 1 &&
      ((b != N && ar[b] >= ar[b + 1]) || (b != 1 && ar[b] >= ar[b - 1]))) {
    swap(ar[a], ar[b]);
    return 0;
  }
  if (!(b & 1) && (ar[b] <= ar[b - 1] || ar[b] <= ar[b + 1])) {
    swap(ar[a], ar[b]);
    return 0;
  }
  used[pair<int, int>(a, b)] = 1;
  swap(ar[a], ar[b]);
  return 1;
}
int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) scanf("%d", &ar[i]);
  for (int i = 1; i <= N; i += 2)
    if (i != 1 && i != N && ar[i] > ar[i - 1] && ar[i] >= ar[i + 1]) {
      must.push_back(i);
      is[i] = 1;
    }
  for (int i = 2; i <= N; i += 2)
    if (i != 1 && i != N && ar[i] < ar[i - 1] && ar[i] <= ar[i + 1]) {
      must.push_back(i);
      is[i] = 1;
    }
  for (int i = 1; i <= N; i += 2)
    if (!is[i]) {
      if (i != 1 && !is[i - 1] && ar[i] >= ar[i - 1])
        oneof.push_back(pair<int, int>(i, i - 1));
      else if (i != N && !is[i + 1] && ar[i] >= ar[i + 1])
        oneof.push_back(pair<int, int>(i, i + 1));
    }
  if (must.size() > 2) nie();
  if (must.size() == 2) {
    if (oneof.size())
      puts("0");
    else
      puts("1");
    return 0;
  }
  if (must.size() == 1) {
    int ans = 0;
    if (oneof.size() > 1) nie();
    if (oneof.size()) {
      pair<int, int> a = oneof[0];
      ans += check(must[0], a.first);
      ans += check(must[0], a.second);
    } else
      for (int i = 1; i <= N; i++) ans += check(i, must[0]);
    cout << ans << endl;
    return 0;
  }
  if (oneof.size() > 2) nie();
  if (oneof.size() == 2) {
    int ans = 0;
    pair<int, int> a = oneof[0], b = oneof[1];
    ans += check(a.first, b.first);
    ans += check(a.first, b.second);
    ans += check(a.second, b.first);
    ans += check(a.second, b.second);
    cout << ans << endl;
    return 0;
  }
  if (oneof.size() == 1) {
    int ans = 0;
    pair<int, int> a = oneof[0];
    for (int i = 1; i <= N; i++) ans += check(i, a.first) + check(i, a.second);
    cout << ans << endl;
  }
  return 0;
}
