#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  string s;
  cin >> s;
  int size = s.size();
  vector<long long int> cnt(26 + 1, 0);
  vector<pair<int, char> > last(26);
  for (int i = 0; i < 26; ++i) last[i] = make_pair(-1, 'a' + i);
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < 26; ++j) {
      if (last[j].second == s[i]) {
        last[j].first = i;
        break;
      }
    }
    sort(last.begin(), last.end());
    int hi = i;
    int k = 1;
    for (int j = 24; j >= 0; --j) {
      int lo = last[j].first;
      if (lo < 0) break;
      cnt[k] += hi - lo;
      hi = lo;
      k++;
    }
    cnt[k] += hi + 1;
  }
  int total = 0;
  for (int i = 1; i < 26; ++i)
    if (cnt[i] == 0)
      break;
    else
      total++;
  cout << total << endl;
  for (int i = 1; i < 26; ++i) {
    if (cnt[i] == 0)
      break;
    else
      cout << cnt[i] << endl;
  }
  return EXIT_SUCCESS;
}
