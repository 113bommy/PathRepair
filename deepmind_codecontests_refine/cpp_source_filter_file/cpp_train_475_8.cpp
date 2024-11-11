#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;
vector<string> arr = {"Anka",        "Chapay", "Cleo", "Dracul",
                      "Hexadecimal", "Snowy",  "Troll"};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  unordered_map<string, int> indices;
  for (int i = 0; i < 7; i++) indices[arr[i]] = i;
  vector<vector<int>> like(7, vector<int>(7, 0));
  for (ll i = 0; i < n; i++) {
    string one, likes, two;
    cin >> one >> likes >> two;
    like[indices[one]][indices[two]] = 1;
  }
  vector<vector<ll>> valid = {{1, 5, 1}, {3, 2, 2}, {4, 2, 1}, {1, 3, 3}};
  vector<ll> scores(3);
  for (ll i = 0; i < 3; i++) cin >> scores[i];
  ll diff = (int)1e9;
  ll likes = 0;
  do {
    for (ll i = 0; i < 3; i++) {
      sort(valid[i].begin(), valid[i].end());
      do {
        ll currLikes = 0;
        ll maxx = 0;
        ll minn = (int)1e9;
        ll pos = 0;
        for (ll j = 0; j < 3; j++) {
          for (ll k = pos; k < pos + valid[i][j]; k++) {
            for (ll l = pos; l < pos + valid[i][j]; l++) {
              currLikes += like[indices[arr[k]]][indices[arr[l]]];
            }
          }
          pos += valid[i][j];
          maxx = max(maxx, scores[j] / valid[i][j]);
          minn = min(minn, scores[j] / valid[i][j]);
        }
        if (maxx - minn < diff) {
          likes = currLikes;
          diff = maxx - minn;
        } else if (maxx - minn == diff)
          likes = max(likes, currLikes);
      } while (next_permutation(valid[i].begin(), valid[i].end()));
    }
  } while (next_permutation(arr.begin(), arr.end()));
  cout << diff << " " << likes;
}
