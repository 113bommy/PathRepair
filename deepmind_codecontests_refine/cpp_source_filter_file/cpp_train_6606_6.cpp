#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
string s1, s2, r;
int p1, p2, k, two[11], do1[4], do2[4];
double ans;
int main() {
  two[0] = 1;
  for (int i = 1; i <= 11; i++) {
    two[i] = two[i - 1] * 2;
  }
  cin >> s1;
  cin >> s2;
  for (int i = 0; i < s1.size(); i++) {
    p1 += (s1[i] == '+' ? 1 : -1);
    if (s1[i] == '+')
      do1[1]++;
    else
      do1[2]++;
  }
  for (int i = 0; i < s2.size(); i++) {
    if (s2[i] == '+')
      do2[1]++;
    else if (s2[i] == '-')
      do2[2]++;
    else
      k++;
  }
  int mx = k - do2[2] + do2[1], mn = 0 - (k + do2[2] - do2[1]);
  if (mn == p1 || mx == p1) {
    printf("%.10lf", 1.0 / two[k]);
    return 0;
  }
  if (mn > p1 || mx < p1) {
    cout << "0.000000000000";
    return 0;
  }
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] == '+') {
      if (do2[1]) {
        do2[1]--;
      } else
        r += '+';
    }
    if (s1[i] == '-') {
      if (do2[2]) {
        do2[2]--;
      } else
        r += '-';
    }
  }
  sort(r.begin(), r.end());
  ans++;
  while (next_permutation(r.begin(), r.end())) {
    ans++;
  }
  printf("%.10lf", ans / ((double)two[k]));
}
