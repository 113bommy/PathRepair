#include <bits/stdc++.h>
using namespace std;
int const MAX_N = 200100;
char st_1[MAX_N], st_2[MAX_N];
int max_cover_bg[MAX_N], max_cover_end[MAX_N];
vector<pair<int, int> > ms[30];
int main() {
  gets(st_1);
  gets(st_2);
  int n = (int)strlen(st_1);
  int m = (int)strlen(st_2);
  int last = 0;
  for (int i = 0; i < n; i++)
    if (st_1[i] == st_2[last]) {
      last++;
      max_cover_bg[i] = last;
      if (last >= m) {
        for (int j = i + 1; j < n; j++) max_cover_bg[j] = last;
        break;
      }
    } else
      max_cover_bg[i] = last;
  last = m - 1;
  for (int i = n - 1; i >= 0; i--)
    if (st_1[i] == st_2[last]) {
      last--;
      max_cover_end[i] = m - 1 - last;
      if (last < 0) {
        for (int j = i - 1; j >= 0; j--) max_cover_end[j] = m - 1 - last;
        break;
      }
    } else
      max_cover_end[i] = m - 1 - last;
  for (int i = 0; i < m; i++) {
    int l = i;
    int r = m - i - 1;
    ms[st_2[i] - 'a'].push_back(make_pair(l, r));
  }
  for (int i = 0; i < n; i++) {
    int l = max_cover_bg[i - 1];
    int r = max_cover_end[i + 1];
    char ch = st_1[i] - 'a';
    int down = 0, up = ms[ch].size();
    while (up > down) {
      int mid = (up + down) / 2;
      if (ms[ch][mid].first > l)
        up = mid;
      else
        down = mid + 1;
    }
    down--;
    if (down >= 0 && down < ms[ch].size()) {
      if (ms[ch][down].second <= r)
        ;
      else {
        printf("No");
        return 0;
      }
    } else {
      printf("No");
      return 0;
    }
  }
  printf("Yes");
  return 0;
}
