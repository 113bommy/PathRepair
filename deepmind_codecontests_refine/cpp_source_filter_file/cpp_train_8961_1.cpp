#include <bits/stdc++.h>
typedef struct stu {
  int num;
  int next;
} stu;
stu *init_stu(int num, int next) {
  stu *root = (stu *)malloc(sizeof(stu));
  root->num = num;
  root->next = next;
  return root;
}
int main() {
  int n;
  scanf("%d", &n);
  stu *culprit[1000];
  for (int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    culprit[i] = init_stu(i + 1, num);
  }
  for (int i = 0; i < n; i++) {
    char hole[1000] = {0};
    int next = i + 1;
    while (hole[next] < 2) {
      hole[next]++;
      if (hole[next] == 2) break;
      next = culprit[next - 1]->next;
    }
    printf("%d ", next);
  }
  return 0;
}
