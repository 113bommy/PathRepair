#include <bits/stdc++.h>
int operations[100005]{0};
int lit_time[100006]{0};
int main() {
  int operation_count, time_length;
  scanf("%d%d", &operation_count, &time_length);
  bool lit = true;
  for (int i = 1; i <= operation_count; ++i) {
    scanf("%d", &operations[i]);
    lit_time[i] += lit_time[i - 1] + lit * (operations[i] - operations[i - 1]);
    lit = !lit;
  }
  lit_time[operation_count + 1] =
      lit_time[operation_count] +
      lit * (time_length - operations[operation_count]);
  int answer = lit_time[operation_count + 1];
  for (int i = 1; i <= operation_count; ++i) {
    answer =
        std::max(answer, lit_time[i] + time_length - operations[i] -
                             (lit_time[operation_count + 1] - lit_time[i]) - 1);
  }
  printf("%d\n", answer);
  return 0;
}
