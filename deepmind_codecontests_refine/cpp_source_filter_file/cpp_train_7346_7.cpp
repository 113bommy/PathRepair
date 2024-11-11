#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  if (n == 1) {
    puts("1\n1");
    exit(0);
  }
  int have = 0;
  vector<int> answer;
  for (int i = 1; i <= n; ++i) {
    if (have + i >= n) break;
    answer.push_back(i);
    have += i;
  }
  have = n - have;
  int Size = answer.size();
  if (have != answer.back())
    answer.push_back(have);
  else
    answer[Size - 1] += have;
  Size = answer.size();
  printf("%d\n", Size);
  for (int &x : answer) printf("%d ", x);
}
