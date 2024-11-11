#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int d() {
  int ret;
  scanf("%d", &ret);
  return ret;
}
long long lld() {
  long long ret;
  scanf("%lld", &ret);
  return ret;
}
int cnt = 0;
vector<int> v;
int n = 10;
void solve(int i) {
  if (cnt == n) {
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
    v.pop_back();
    cnt--;
  }
  v.push_back(i);
  cnt++;
  solve(i + 1);
  v.pop_back();
  v.push_back(i + 1);
  cnt++;
  solve(i + 1);
  v.pop_back();
}
int arr[500];
int main() {
  int t = d();
  while (t--) {
    int n = d();
    for (int i = 0; i < n; i++) scanf("%d", arr + i);
    bool flag = true;
    if (n == 1) {
      puts("YES");
      continue;
    }
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        if (arr[0] - 1 == arr[n - 1] || arr[0] - 1 == arr[1] || arr[0] == 1) {
        } else
          flag = false;
      } else if (i == n - 1) {
        if (arr[n - 1] - 1 == arr[0] || arr[n - 1] - 1 == arr[n - 2] ||
            arr[n - 1] == 0) {
        } else
          flag = false;
      } else {
        if (arr[i] - 1 == arr[i - 1] || arr[i] - 1 == arr[i + 1] ||
            arr[i] == 1) {
        } else
          flag = false;
      }
    }
    if (flag)
      puts("YES");
    else
      puts("NO");
  }
}
