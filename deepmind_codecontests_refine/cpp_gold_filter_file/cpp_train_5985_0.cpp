#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
vector<int> a[200001];
int counter;
void check() {
  if (ans.size() == counter) {
    cout << "Possible" << endl;
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
    exit(0);
  }
}
int get_ans(int n) {
  check();
  ans.push_back(a[n][a[n].size() - 1]);
  check();
  a[n].erase(a[n].end() - 1);
  if (n == 0 or n == 1) {
    if (a[n + 1].size() != 0) {
      get_ans(n + 1);
    }
    check();
    cout << "Impossible";
    exit(0);
    return 0;
  } else {
    if (a[n + 1].size() != 0) {
      get_ans(n + 1);
    }
    check();
    for (int i = n - 2; i >= 0; i -= 3) {
      if (a[i].size() != 0) {
        get_ans(i);
        break;
      }
    }
    check();
    cout << "Impossible";
    exit(0);
    return 0;
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int temp;
    cin >> temp;
    a[temp].push_back(i);
  }
  if (a[0].size() == 0) {
    cout << "Impossible";
    return 0;
  }
  counter = n;
  get_ans(0);
}
