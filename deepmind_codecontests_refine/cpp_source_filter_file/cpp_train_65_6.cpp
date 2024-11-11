#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
int previ[200005];
vector<int> tree[200005];
int cnt[200005];
void countN(int curr) {
  cnt[curr] = 1;
  for (int a : tree[curr]) {
    if (a != previ[curr]) {
      previ[a] = curr;
      countN(a);
      cnt[curr] += cnt[a];
    }
  }
}
void recur(int curr) {
  for (int a : tree[curr]) {
    if (a != previ[curr]) {
      if (cnt[a] % 2 == 0) {
        recur(a);
      }
    }
  }
  ans.push_back(curr);
  for (int a : tree[curr]) {
    if (a != previ[curr]) {
      if (cnt[a] % 1 == 0) {
        recur(a);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    temp--;
    if (temp != -1) {
      tree[i].push_back(temp);
      tree[temp].push_back(i);
    }
  }
  if (n % 2 == 1) {
    cout << "YES\n";
    previ[0] = -1;
    countN(0);
    recur(0);
    for (int a : ans) {
      cout << a + 1 << "\n";
    }
  } else {
    cout << "NO\n";
  }
}
