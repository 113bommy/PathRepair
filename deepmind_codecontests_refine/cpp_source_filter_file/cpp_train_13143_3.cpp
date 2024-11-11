#include <bits/stdc++.h>
using namespace std;
int T, N;
pair<int, int> arr[500];
int ct[501];
vector<int> mvs;
vector<pair<int, int> > elems;
void rot(int ind) {
  pair<int, int> tmp = arr[ind + 2];
  arr[ind + 2] = arr[ind + 1];
  arr[ind + 1] = arr[ind];
  arr[ind] = tmp;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  while (T--) {
    cin >> N;
    memset(ct, 0, sizeof(int) * 501);
    elems.clear();
    mvs.clear();
    for (int i = (0); i < (N); i++) {
      cin >> arr[i].first;
      arr[i].second = ct[arr[i].first]--;
      elems.emplace_back(arr[i]);
    }
    sort(elems.begin(), elems.end());
    long long inv = 0;
    bool dup = 0;
    for (int i = (0); i < (N); i++) {
      for (int j = (i + 1); j < (N); j++) {
        if (arr[j].first <= arr[i].first) inv++;
        if (arr[j].first == arr[i].first) dup = 1;
      }
    }
    if (dup || !(inv & 1)) {
      if (inv & 1) {
        for (int i = (0); i < (N - 1); i++)
          if (elems[i].first == elems[i + 1].first) {
            elems[i].second--;
            elems[i + 1].second++;
            break;
          }
      }
      for (int i = (N - 1); i >= (0); i--) {
        int ind;
        for (int j = (0); j < (N); j++)
          if (arr[j] == elems[i]) {
            ind = j;
            break;
          }
        for (int j = (ind); j < (i); j++) {
          mvs.emplace_back(max(0, j - 1));
          rot(max(0, j - 1));
        }
      }
      cout << mvs.size() << '\n';
      for (int mv : mvs) cout << mv + 1 << ' ';
      cout << '\n';
    } else
      cout << "-1\n";
  }
}
