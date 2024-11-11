#include <bits/stdc++.h>
using namespace std;
struct node {
  int num;
  int num_num;
} num[105];
int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  num[0].num = 0;
  num[0].num_num = 0;
  for (int i = 1; i <= N; i++) {
    int flag;
    scanf("%d", &flag);
    num[i].num = num[i - 1].num + flag;
    num[i].num_num = 0;
  }
  while (M--) {
    int left, right;
    scanf("%d%d", &left, &right);
    if (left == right && num[left].num - num[left - 1].num > 0)
      num[left].num_num++;
    else if (left < right && num[right].num - num[left].num >= 0) {
      for (int i = left; i <= right; i++) num[i].num_num++;
    }
  }
  long long int sum = 0;
  for (int i = 1; i <= N; i++) {
    sum += (num[i].num - num[i - 1].num) * num[i].num_num;
  }
  printf("%I64d\n", sum);
  return 0;
}
