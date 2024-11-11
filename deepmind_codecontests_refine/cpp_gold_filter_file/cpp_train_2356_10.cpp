#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  int answer = 0;
  for (int i = 1; i + 1 < n; ++i)
    if (a[i] > a[i - 1] && a[i] > a[i + 1])
      ++answer;
    else if (a[i] < a[i - 1] && a[i] < a[i + 1])
      ++answer;
  printf("%d\n", answer);
  return 0;
}
