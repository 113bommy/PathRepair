#include <bits/stdc++.h>
using namespace std;
vector<int> alice;
vector<int> bob;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    alice.push_back(a);
  }
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    bob.push_back(a);
  }
  sort(alice.begin(), alice.end());
  sort(bob.begin(), bob.end());
  for (int i = 0; i < bob.size(); i++) {
    while (i != bob.size() - 1 && bob[i + 1] == bob[i]) i++;
    int chan =
        (upper_bound(alice.begin(), alice.end(), bob[i]) - alice.begin());
    chan = alice.size() - chan;
    if (chan > bob.size() - i - 1) {
      cout << "YES";
      return 0;
    }
  }
  if (alice.size() > bob.size()) {
    cout << "YES";
    return 0;
  }
  cout << "NO";
  return 0;
}
