#include <bits/stdc++.h>
using namespace std;
void solve();
int main(int argc, char const *argv[]) { solve(); }
void solve() {
  map<int, int> arr;
  cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
  int total = arr[0] + arr[1] + arr[2] + arr[3];
  for (int st = 0; st < 4; st++)
    if (arr[st]) {
      vector<int> res;
      auto t = arr;
      arr[st]--;
      res.push_back(st);
      int last = st;
      for (int i = 0; i < total - 1; i++) {
        if (t[last - 1]) {
          t[last - 1]--;
          res.push_back(last - 1);
          last--;
        } else if (t[last + 1]) {
          t[last + 1]--;
          res.push_back(last + 1);
          last++;
        } else
          break;
      }
      if ((int)res.size() == total) {
        cout << "YES\n";
        for (int i : res) printf("%d ", i);
        cout << endl;
        return;
      }
    }
  cout << "NO\n";
  return;
}
