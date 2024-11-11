#include <bits/stdc++.h>
using namespace std;
struct range {
  int l, r;

 public:
  range(int a, int b) {
    l = a;
    r = b;
  }
  range() {}
};
int main() {
  range arr[300300];
  int n, a, b, k;
  cin >> n >> k;
  pair<int, int> toGo[300300];
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    arr[i] = range(a, b);
    toGo[i] = make_pair(a, i);
  }
  sort(toGo, toGo + n);
  multiset<int> ends;
  int res = 0;
  int sst, send;
  for (int i = 0; i < n; i++) {
    ends.insert(arr[toGo[i].second].r);
    if (ends.size() > k) ends.erase(ends.begin());
    if (ends.size() == k) {
      int st = toGo[i].first;
      if (*ends.begin() - toGo[i].first + 1 > res) {
        res = *ends.begin() - toGo[i].first + 1;
        sst = toGo[i].first;
        send = *ends.begin();
      }
    }
  }
  cout << res << endl;
  for (int i = 0; i < n; i++)
    if ((arr[i].l <= sst && arr[i].r >= send) || res == 0) {
      cout << i + 1 << " ";
      k--;
      if (k == 0) break;
    }
}
