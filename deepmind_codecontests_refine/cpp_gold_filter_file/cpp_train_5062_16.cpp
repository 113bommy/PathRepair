#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
template <typename T>
T pow(T a, T b, long long m) {
  T ans = 1;
  a = a % m;
  while (b > 0) {
    if (b % 2 == 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans % m;
}
template <typename T>
T modInv(T a, T m) {
  return pow(a, m - 2, m);
}
bool check = true;
int cap[100005];
vector<int> children[100005];
bool checked[100005];
void makeCap(int x) {
  if (cap[x] == 0)
    check = false;
  else
    cap[x] = 1;
}
void makeSmall(int x) {
  if (cap[x] == 1)
    check = false;
  else
    cap[x] = 0;
}
void makeDepend(int x, int y) { children[x].push_back(y); }
void evaluate(int x) {
  if (checked[x]) return;
  if (cap[x] != 1) return;
  checked[x] = true;
  for (auto it : children[x]) {
    makeCap(it);
    evaluate(it);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  fill(cap, cap + m + 5, -1);
  fill(checked, checked + m + 5, false);
  vector<int> v1, v2;
  int x;
  cin >> x;
  for (int i = 0; i < x; i++) {
    int t;
    cin >> t;
    v2.push_back(t);
  }
  for (int j = 1; j < n; j++) {
    v1 = v2;
    v2.clear();
    x = v1.size();
    int y;
    cin >> y;
    for (int i = 0; i < y; i++) {
      int t;
      cin >> t;
      v2.push_back(t);
    }
    bool flag1 = true;
    for (int i = 0; i < min(x, y); i++) {
      if (v1[i] != v2[i]) flag1 = false;
    }
    if (x <= y && flag1) continue;
    if (x > y && flag1) {
      check = false;
      break;
    }
    for (int i = 0; i < min(x, y); i++) {
      if (v1[i] == v2[i]) continue;
      if (v1[i] > v2[i]) {
        makeCap(v1[i]);
        makeSmall(v2[i]);
      }
      if (v1[i] < v2[i]) {
        makeDepend(v2[i], v1[i]);
      }
      break;
    }
  }
  for (int i = 1; i <= m; i++) {
    evaluate(i);
  }
  vector<int> answer;
  for (int i = 1; i <= m; i++) {
    if (cap[i] == 1) answer.push_back(i);
  }
  if (!check)
    cout << "No"
         << "\n";
  else {
    cout << "Yes"
         << "\n";
    cout << answer.size() << "\n";
    for (auto it : answer) cout << it << " ";
  }
  return 0;
}
