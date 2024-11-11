#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300010;
int a[MAXN];
int b[MAXN];
vector<int> p;
int main() {
  int n, k, c;
  cin >> n >> k >> c;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > k) {
      p.push_back(count);
      count = 0;
      continue;
    }
    count++;
  }
  p.push_back(count);
  int answer = 0;
  for (int i = 0; i < p.size(); i++) {
    answer += p[i] - c + 1;
  }
  cout << answer;
}
