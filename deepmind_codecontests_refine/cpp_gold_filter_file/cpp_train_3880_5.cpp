#include <bits/stdc++.h>
using namespace std;
int best = 0;
int trail_zero = 0;
int last_no = -1;
char buf[120000];
int jml[2][10];
int main() {
  scanf("%s", buf);
  int n = strlen(buf);
  for (int(i) = 0; (i) < (10); ++(i)) jml[0][i] = jml[1][i] = 0;
  for (int(i) = 0; (i) < (n); ++(i)) {
    jml[0][buf[i] - '0']++;
    jml[1][buf[i] - '0']++;
  }
  best = 0;
  for (int(i) = 0; (i) < (jml[0][0] + 1); ++(i)) {
    if (best < i) {
      best = i;
      trail_zero = i;
      last_no = -1;
    }
    jml[0][0] -= i;
    jml[1][0] -= i;
    for (int(j) = (1); (j) < (10); ++(j)) {
      if (jml[0][j] && jml[1][10 - j]) {
        int matches = i + 1;
        jml[0][j] -= 1;
        jml[1][10 - j] -= 1;
        for (int(k) = 0; (k) < (10); ++(k))
          matches += min(jml[0][k], jml[1][9 - k]);
        jml[0][j] += 1;
        jml[1][10 - j] += 1;
        if (best < matches) {
          best = matches;
          trail_zero = i;
          last_no = j;
        }
      }
    }
    jml[0][0] += i;
    jml[1][0] += i;
  }
  if (best == 0) {
    printf("%s\n%s\n", buf, buf);
  } else {
    vector<int> best1, best2;
    for (int i = 0; i < trail_zero; ++i) {
      best1.push_back(0);
      best2.push_back(0);
      jml[1][0]--;
      jml[0][0]--;
    }
    if (last_no != -1) {
      jml[0][last_no]--;
      jml[1][10 - last_no]--;
      best1.push_back(last_no);
      best2.push_back(10 - last_no);
      for (int(i) = 0; (i) < (10); ++(i)) {
        int k = min(jml[0][i], jml[1][9 - i]);
        for (int(j) = 0; (j) < (k); ++(j)) {
          jml[0][i]--;
          jml[1][9 - i]--;
          best1.push_back(i);
          best2.push_back(9 - i);
        }
      }
    }
    for (int(i) = 0; (i) < (10); ++(i))
      for (int(k) = 0; (k) < (jml[0][i]); ++(k)) best1.push_back(i);
    for (int(i) = 0; (i) < (10); ++(i))
      for (int(k) = 0; (k) < (jml[1][i]); ++(k)) best2.push_back(i);
    reverse(best1.begin(), best1.end());
    reverse(best2.begin(), best2.end());
    for (int(i) = 0; (i) < (((int)best1.size())); ++(i))
      printf("%c", (char)('0' + best1[i]));
    cout << endl;
    for (int(j) = 0; (j) < (((int)best2.size())); ++(j))
      printf("%c", (char)('0' + best2[j]));
    cout << endl;
  }
}
