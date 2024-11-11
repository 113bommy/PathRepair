#include <bits/stdc++.h>
using namespace std;
int T, N;
pair<pair<int, int>, int> input[200001];
struct sorter1 {
  bool operator()(const pair<pair<int, int>, int> &a,
                  const pair<pair<int, int>, int> &b) {
    return a.first.first + a.first.second < b.first.first + b.first.second;
  }
};
struct sorter3 {
  bool operator()(const pair<pair<int, int>, int> &a,
                  const pair<pair<int, int>, int> &b) {
    return a.first.second < b.first.second;
  }
};
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    long long sum_o = 0, sum_r = 0;
    for (int i = 0; i < 2 * N - 1; i++) {
      scanf("%d%d", &input[i].first.first, &input[i].first.second);
      input[i].second = i + 1;
      sum_o += input[i].first.first;
      sum_r += input[i].first.second;
    }
    sum_o++;
    sum_r++;
    long long t_o, t_r;
    std::sort(input, input + 2 * N - 1, sorter1());
    reverse(input, input + 2 * N - 1);
    t_o = t_r = 0;
    for (int i = 0; i < N; i++) {
      t_o += input[i].first.first;
      t_r += input[i].first.second;
    }
    if (t_o >= sum_o / 2 && t_r >= sum_r / 2) {
      puts("YES");
      for (int i = 0; i < N; i++) {
        printf("%d ", input[i].second);
      }
      puts("");
      fflush(stdout);
      continue;
    }
    std::sort(input, input + 2 * N - 1);
    reverse(input, input + 2 * N - 1);
    t_o = t_r = 0;
    for (int i = 0; i < N; i++) {
      t_o += input[i].first.first;
      t_r += input[i].first.second;
    }
    if (t_o >= sum_o / 2 && t_r >= sum_r / 2) {
      puts("YES");
      for (int i = 0; i < N; i++) {
        printf("%d ", input[i].second);
      }
      puts("");
      fflush(stdout);
      continue;
    }
    std::sort(input, input + 2 * N - 1, sorter3());
    reverse(input, input + 2 * N - 1);
    t_o = t_r = 0;
    for (int i = 0; i < N; i++) {
      t_o += input[i].first.first;
      t_r += input[i].first.second;
    }
    if (t_o >= sum_o / 2 && t_r >= sum_r / 2) {
      puts("YES");
      for (int i = 0; i < N; i++) {
        printf("%d ", input[i].second);
      }
      puts("");
      fflush(stdout);
      continue;
    }
    for (int i = 0; i < 1000; i++) {
      random_shuffle(input, input + 2 * N - 1);
      t_o = t_r = 0;
      for (int i = 0; i < N; i++) {
        t_o += input[i].first.first;
        t_r += input[i].first.second;
      }
      if (t_o >= sum_o / 2 && t_r >= sum_r / 2) {
        puts("YES");
        for (int i = 0; i < N; i++) {
          printf("%d ", input[i].second);
        }
        puts("");
        fflush(stdout);
        break;
      }
    }
  }
  return 0;
}
