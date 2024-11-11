#include <bits/stdc++.h>
using namespace std;
set<pair<string, string> > st;
int main() {
  char s1[20], s2[20];
  string ppl[] = {"",      "Anka",   "Chapay", "Cleo",
                  "Troll", "Dracul", "Snowy",  "Hexadecimal"};
  sort(ppl + 1, ppl + 8);
  int n;
  scanf("%d\n", &n);
  for (int i = 0; i < n; ++i) {
    string a, b, c;
    char s1[20], s2[20];
    scanf("%s likes %s\n", &s1, &s2);
    st.insert({string(s1), string(s2)});
  }
  int arr[3], mndiff = 999999999, mxlikes = 0;
  scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
  do {
    for (int i = 1; i <= 5; i++) {
      for (int j = 1; j + i <= 6; j++) {
        swap(arr[0], arr[2]);
        do {
          int tmpmn = min(arr[0] / i, min(arr[1] / j, arr[2] / (7 - i - j)));
          int tmpmx = max(arr[0] / i, max(arr[1] / j, arr[2] / (7 - i - j)));
          int tmpdiff = tmpmx - tmpmn;
          int tmplikes = 0;
          for (int ii = 1; ii <= i; ii++) {
            for (int jj = 1; jj <= i; jj++) {
              tmplikes += st.find({ppl[ii], ppl[jj]}) != st.end();
            }
          }
          for (int ii = 1; ii <= j; ii++) {
            for (int jj = 1; jj <= j; jj++) {
              tmplikes += st.find({ppl[i + ii], ppl[i + jj]}) != st.end();
            }
          }
          for (int ii = 1; ii <= 7 - i - j; ii++) {
            for (int jj = 1; jj <= 7 - i - j; jj++) {
              tmplikes +=
                  st.find({ppl[i + j + ii], ppl[i + j + jj]}) != st.end();
            }
          }
          if (tmpdiff < mndiff) {
            mndiff = tmpdiff;
            mxlikes = tmplikes;
          } else if (tmpdiff == mndiff) {
            mxlikes = max(mxlikes, tmplikes);
          }
        } while (next_permutation(arr, arr + 3));
      }
    }
  } while (next_permutation(ppl + 1, ppl + 8));
  cout << mndiff << ' ' << mxlikes << '\n';
  return 0;
}
