#include <bits/stdc++.h>
using namespace std;
const int MaxN = 111;
int op[123456], val[123456], b[123456];
vector<int> x;
vector<int>::iterator it;
long long sum[333][5];
int k[333], sumk;
map<int, int> ma;
char s[5];
int main(void) {
  int i, j, n;
  int no, ni;
  long long res;
  scanf("%d", &n);
  x.clear();
  for (i = 0; i < n; i++) {
    scanf(" %s", s);
    if (s[0] == 'a')
      op[i] = 1;
    else if (s[0] == 'd')
      op[i] = 2;
    else
      op[i] = 3;
    if (op[i] < 3) {
      scanf("%d", &val[i]);
      x.push_back(val[i]);
    }
  }
  sort(x.begin(), x.end());
  it = unique(x.begin(), x.end());
  x.resize(it - x.begin());
  for (i = 0; i < x.size(); i++) ma[x[i]] = i;
  memset(sum, 0, sizeof(sum));
  memset(k, 0, sizeof(k));
  memset(b, 0, sizeof(b));
  for (i = 0; i < n; i++) {
    if (op[i] == 1) {
      b[ma[val[i]]]++;
      no = ma[val[i]] / 320;
      k[no]++;
      for (j = 0; j < 5; j++) sum[no][j] = 0;
      j = 0;
      for (ni = 0; ni < 320; ni++) {
        if (b[no * 320 + ni]) {
          sum[no][j] = sum[no][j] + x[no * 320 + ni];
          j++;
          if (j == 5) j = 0;
        }
      }
    } else if (op[i] == 2) {
      b[ma[val[i]]]--;
      no = ma[val[i]] / 320;
      k[no]--;
      for (j = 0; j < 5; j++) sum[no][j] = 0;
      j = 0;
      for (ni = 0; ni < 320; ni++) {
        if (b[no * 320 + ni]) {
          sum[no][j] = sum[no][j] + x[no * 320 + ni];
          j++;
          if (j == 5) j = 0;
        }
      }
    } else if (op[i] == 3) {
      res = 0;
      sumk = 2;
      for (no = 0; no < 320; no++) {
        res += sum[no][4 - sumk % 5];
        sumk += k[no];
      }
      printf("%I64d\n", res);
    }
  }
  return 0;
}
