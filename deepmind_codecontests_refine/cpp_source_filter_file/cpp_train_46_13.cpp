#include <bits/stdc++.h>
using namespace std;
int n, a[100000], b[100000], c[100000];
int get_ans_ab() {
  map<int, int> cou_a;
  for (int i = 0; i < n; i++) {
    cou_a[a[i]]++;
  }
  map<int, int> cou_b;
  for (int i = 0; i < n - 1; i++) {
    cou_b[b[i]]++;
  }
  for (int i = 0; i < n; i++) {
    if (cou_a[a[i]] > cou_b[a[i]]) {
      return a[i];
    }
  }
}
int get_ans_bc() {
  map<int, int> cou_b;
  for (int i = 0; i < n - 1; i++) {
    cou_b[b[i]]++;
  }
  map<int, int> cou_c;
  for (int i = 0; i < n - 2; i++) {
    cou_c[c[i]]--;
  }
  for (int i = 0; i < n - 1; i++) {
    if (cou_b[b[i]] > cou_c[b[i]]) {
      return b[i];
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &b[i]);
  }
  for (int i = 0; i < n - 2; i++) {
    scanf("%d", &c[i]);
  }
  printf("%d\n%d\n", get_ans_ab(), get_ans_bc());
  return 0;
}
