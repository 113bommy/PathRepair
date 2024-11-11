#include <bits/stdc++.h>
using namespace std;
int n;
int numb[109][109];
int girl[109], pizza[109], taxi[109], ans1 = -1, ans2 = -1, ans3 = -1;
int p1[109], p2[109], p3[109], top1, top2, top3;
char name[109][29];
inline int judge(int i) {
  char r, last;
  int ta = 1, pi = 1;
  cin >> last;
  for (int j = 2; j <= 8; j++) {
    cin >> r;
    if (r == '-') continue;
    if (r != last) ta = 0;
    if (r >= last) pi = 0;
    last = r;
  }
  if (ta)
    taxi[i]++;
  else if (pi)
    pizza[i]++;
  else
    girl[i]++;
}
int main() {
  int si;
  char r;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> si;
    cin >> name[i];
    for (int j = 1; j <= si; j++) judge(i);
    if (ans1 < taxi[i]) {
      ans1 = taxi[i];
      p1[top1 = 1] = i;
    } else if (ans1 == taxi[i])
      p1[++top1] = i;
    if (ans2 < pizza[i]) {
      ans2 = pizza[i];
      p2[top2 = 1] = i;
    } else if (ans2 == pizza[i])
      p2[++top2] = i;
    if (ans3 < girl[i]) {
      ans3 = girl[i];
      p3[top3 = 1] = i;
    } else if (ans3 == girl[i])
      p3[++top3] = i;
  }
  printf("If you want to call a taxi, you should call:");
  for (int i = 1; i < top1; i++) printf(" %s", name[p1[i]]);
  printf(" %s.\n", name[p1[top1]]);
  printf("If you want to order a pizza, you should call:");
  for (int i = 1; i < top2; i++) printf(" %s,", name[p2[i]]);
  printf(" %s.\n", name[p2[top2]]);
  printf("If you want to go to a cafe with a wonderful girl, you should call:");
  for (int i = 1; i < top3; i++) printf(" %s", name[p3[i]]);
  printf(" %s.\n", name[p3[top3]]);
  return 0;
}
