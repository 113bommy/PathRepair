#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long maximum(n + 1);
  vector<int> switches;
  vector<long long> ways(4);
  ways[1] = 1;
  ways[2] = 2;
  ways[3] = 3;
  while (k > ways[ways.size() - 1]) {
    int i = ways.size();
    ways.push_back(ways[i - 1] + ways[i - 2]);
  }
  while (k + 1 > 0) {
    int i = 1;
    while (k > ways[i]) i++;
    switches.push_back(i);
    k -= (ways[i - 1] + 1);
  }
  vector<int> result(n + 1);
  for (long long i = 1; i <= (int)n; i++) result[i] = i;
  for (long long i = 0; i < (int)switches.size(); i++) {
    if (switches[i] > 1)
      swap(result[n - switches[i] + 1], result[n - switches[i] + 2]);
  }
  for (long long i = 1; i <= (int)n; i++) cout << result[i] << " ";
  return 0;
}
