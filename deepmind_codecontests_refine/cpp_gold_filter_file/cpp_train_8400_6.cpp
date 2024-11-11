#include <bits/stdc++.h>
using namespace std;
struct data {
  int w;
  int n;
};
bool compare(data w1, data w2) { return w1.w > w2.w; }
int main() {
  int n;
  cin >> n;
  vector<data> wi(n), we;
  for (int i = 0; i < n; i++) {
    cin >> wi[i].w;
    wi[i].n = i;
  }
  sort(wi.begin(), wi.end(), compare);
  vector<char> s(2 * n);
  int k = n;
  for (int i = 0; i < 2 * n; i++) {
    cin >> s[i];
    if (s[i] == '0') {
      cout << wi[k - 1].n + 1 << " ";
      we.push_back(wi[k - 1]);
      wi.pop_back();
      k--;
    } else {
      cout << (*(we.end() - 1)).n + 1 << " ";
      we.pop_back();
    }
  }
  return 0;
}
