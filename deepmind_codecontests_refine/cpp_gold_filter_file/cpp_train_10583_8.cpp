#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int inf = (int)(1e9);
const int MAX_N = 100 + 10;
vector<pair<int, int> > v;
string arr[MAX_N], w;
int n, used[MAX_N];
char let;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  cin >> w;
  cin >> let;
  for (int k = 0; k < n; k++) {
    string cur = arr[k];
    for (int i = 0; i < ((int)w.size()); i++) {
      int j;
      for (j = i; j - i < ((int)cur.size()) && j < ((int)w.size()) &&
                  tolower(cur[j - i]) == tolower(w[j]);
           j++)
        ;
      if (j - i == ((int)cur.size()))
        v.push_back(pair<int, int>(i, ((int)cur.size())));
    }
  }
  string next = w;
  for (int i = 0; i < ((int)v.size()); i++) {
    int idx = v[i].first;
    for (int j = 0; j < v[i].second; j++) {
      if (used[idx + j]) continue;
      used[idx + j] = 1;
      char ch = w[idx + j];
      if (tolower(ch) == let) {
        if (let == 'a')
          next[idx + j] = (isupper(ch) ? 'B' : 'b');
        else
          next[idx + j] = (isupper(ch) ? 'A' : 'a');
      } else
        next[idx + j] = let - (isupper(ch) ? 'a' - 'A' : 0);
    }
  }
  cout << next << endl;
  return 0;
}
