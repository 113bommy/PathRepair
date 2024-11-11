#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  static int data[1200500];
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N * 2; i++) scanf("%d", data + i);
  sort(data, data + 2 * N);
  long long res = ((long long)(data[N - 1] - data[0])) *
                  ((long long)(data[2 * N - 1] - data[N]));
  for (int i = 1; i < N - 1; i++)
    res = min(res, ((long long)(data[2 * N - 1] - data[0])) *
                       ((long long)(data[N + i] - data[i])));
  cout << res << endl;
  return 0;
}
