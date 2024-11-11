#include <bits/stdc++.h>
const long long mod = 1000000007L;
using namespace std;
int ar[1010];
queue<int> q;
std::vector<int> edge;
void solve(int n, int minv, int maxv) {
  while (ar[n] == 0) {
    int t = q.front();
    q.pop();
    for (int i : edge) {
      if (i + t >= minv && i + t <= maxv && ar[i + t] == 0) {
        ar[i + t] = ar[t] + 1;
        q.push(i + t);
      }
    }
  }
  cout << ar[n] << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int maxv = -1000, minv = 1000;
  for (int i = 0, a; i < k; i++) {
    cin >> a;
    ar[a] = 1;
    maxv = max(maxv, a);
    minv = min(minv, a);
  }
  if (n > maxv || n < minv) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 0; i <= 1000; i++) {
    if (ar[i]) {
      q.push(i);
      edge.push_back(i - n);
    }
  }
  solve(n, minv, maxv);
  return 0;
}
