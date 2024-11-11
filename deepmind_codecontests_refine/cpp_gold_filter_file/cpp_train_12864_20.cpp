#include <bits/stdc++.h>
using namespace std;
long long int n;
vector<long long int> ttime;
vector<long long int> min_cost;
long long int minimum(long long int a, long long int b) {
  return a < b ? a : b;
}
long long int find_index(long long int i) {
  long long int start = 0, last = n - 1, mid;
  mid = (start + last) / 2;
  while ((start < last) && (ttime[mid] != i)) {
    if (i < ttime[mid])
      last = mid;
    else if (i > ttime[mid])
      start = mid;
    mid = (start + last) / 2;
    if ((last - start) == 1) break;
  }
  if (ttime[mid] >= i)
    return mid;
  else
    return last;
}
long long int findmin(long long int i) {
  if (i == 0) return 20;
  long long int time2 = find_index(ttime[i] - 89);
  long long int time3 = find_index(ttime[i] - 1439);
  long long int mintime2, mintime3;
  if (time2 != 0)
    mintime2 = min_cost[time2 - 1] + 50;
  else
    mintime2 = 50;
  if (time3 != 0)
    mintime3 = min_cost[time3 - 1] + 120;
  else
    mintime3 = 120;
  return minimum(min_cost[i - 1] + 20, minimum(mintime2, mintime3));
}
int main() {
  long long int temp, sum = 0;
  cin >> n;
  min_cost.resize(n, 1000000);
  for (long long int i = 0; i < n; i++) {
    cin >> temp;
    ttime.push_back(temp);
  }
  for (long long int i = 0; i < n; i++) {
    min_cost[i] = findmin(i);
    cout << min_cost[i] - sum << endl;
    sum = min_cost[i];
  }
  return 0;
}
