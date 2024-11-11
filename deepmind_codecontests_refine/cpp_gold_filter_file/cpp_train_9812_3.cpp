#include <bits/stdc++.h>
using namespace std;
bool is_sq(vector<pair<int, int> > all, int i, int j, int k, int l) {
  if ((all[i].first - all[j].first) * (all[i].first - all[j].first) +
          (all[i].second - all[j].second) * (all[i].second - all[j].second) ==
      (all[i].first - all[k].first) * (all[i].first - all[k].first) +
          (all[i].second - all[k].second) * (all[i].second - all[k].second)) {
    if ((all[i].first - all[j].first) * (all[i].first - all[k].first) +
            (all[i].second - all[j].second) * (all[i].second - all[k].second) ==
        0) {
      if ((all[l].first - all[j].first) * (all[l].first - all[j].first) +
              (all[l].second - all[j].second) *
                  (all[l].second - all[j].second) ==
          (all[l].first - all[k].first) * (all[l].first - all[k].first) +
              (all[l].second - all[k].second) *
                  (all[l].second - all[k].second)) {
        if ((all[l].first - all[j].first) * (all[l].first - all[k].first) +
                (all[l].second - all[j].second) *
                    (all[l].second - all[k].second) ==
            0) {
          return true;
        }
      }
    }
  }
  return false;
}
bool is_rec(vector<pair<int, int> > all, int i, int j, int k, int l) {
  if ((all[i].first - all[j].first) * (all[i].first - all[k].first) +
          (all[i].second - all[j].second) * (all[i].second - all[k].second) ==
      0) {
    if ((all[l].first - all[j].first) * (all[l].first - all[k].first) +
            (all[l].second - all[j].second) * (all[l].second - all[k].second) ==
        0) {
      return true;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<pair<int, int> > all(8);
  for (int i = 0; i < 8; i++) cin >> all[i].first >> all[i].second;
  for (int i = 0; i < 8; i++) {
    for (int j = i + 1; j < 8; j++) {
      for (int k = j + 1; k < 8; k++) {
        for (int l = k + 1; l < 8; l++) {
          int tags, tagr;
          tags = tagr = 0;
          vector<int> sq, rc;
          sq.push_back(i);
          sq.push_back(j);
          sq.push_back(k);
          sq.push_back(l);
          for (int x = 0; x < 8; x++) {
            if (x != i && x != j && x != k && x != l) rc.push_back(x);
          }
          do {
            if (is_sq(all, sq[0], sq[1], sq[2], sq[3])) {
              tags = 1;
              break;
            }
          } while (next_permutation(sq.begin(), sq.end()));
          do {
            if (is_rec(all, rc[0], rc[1], rc[2], rc[3])) {
              tagr = 1;
              break;
            }
          } while (next_permutation(rc.begin(), rc.end()));
          if (tags && tagr) {
            cout << "YES\n";
            for (int i = 0; i < 4; i++) cout << sq[i] + 1 << " ";
            cout << endl;
            for (int i = 0; i < 4; i++) cout << rc[i] + 1 << " ";
            return 0;
          }
        }
      }
    }
  }
  cout << "NO\n";
}
