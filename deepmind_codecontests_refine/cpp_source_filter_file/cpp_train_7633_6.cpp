#include <bits/stdc++.h>
using namespace std;
struct Student {
  int t;
  int x;
  int ind;
  int out;
};
bool sort_x(Student s1, Student s2) { return s1.x < s2.x; }
bool sort_ind(Student s1, Student s2) { return s1.ind < s2.ind; }
Student s[100005];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &s[i].t, &s[i].x);
    s[i].ind = i;
  }
  int sum = 0;
  int tsum = 0;
  for (int i = 0; i < n; i++) {
    sum++;
    if (sum == m || i == n - 1) {
      if (tsum < s[i].t) tsum = s[i].t;
      int j = i - (sum - 1);
      sort(&s[j], &s[j + sum], sort_x);
      for (int k = j; k < j + sum;) {
        int c = 0;
        while (s[k].x == s[k + c].x && k + c < i + sum) c++;
        for (int p = 0; p < c; p++) {
          s[k + p].out = tsum + s[k].x;
        }
        k += c;
        tsum += 1 + c / 2;
      }
      tsum += s[j + sum - 1].x * 2;
      sum = 0;
    }
  }
  sort(s, s + n, sort_ind);
  for (int i = 0; i < n - 1; i++) printf("%d ", s[i].out);
  printf("%d\n", s[n - 1].out);
  return 0;
}
