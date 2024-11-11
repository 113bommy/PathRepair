#include <bits/stdc++.h>
using namespace std;
bool seats[100][100];
long long calc(long long x, long long start, long long num, long long xc,
               long long yc) {
  long long ans = 0;
  for (long long i = start; i < num + start; i++) {
    ans += abs(xc - x) + abs(yc - i);
  }
  return ans;
}
long long findLongestEmptyStartingFrom(int x, int start, int k) {
  int count = 0;
  while (start < k and seats[x][start] == 0) {
    count++;
    start++;
  }
  return count;
}
long long findBestInThisRow(int x, int k, int req) {
  long long ans = -1;
  int cost = INT_MAX;
  for (int i = 0; i < k; i++) {
    if (!seats[x][i]) {
      int count = findLongestEmptyStartingFrom(x, i, k);
      if (count < req) {
        continue;
      } else {
        while (count >= req) {
          int costt = calc(x, i, req, k / 2, k / 2);
          if (costt < cost) {
            cost = costt;
            ans = i;
          }
          i++;
          count--;
        }
      }
    }
  }
  return ans;
}
pair<long long, long long> findBestRowBestPlacement(int k, int req) {
  int ans = INT_MAX;
  int rowIndex = -1;
  int colIndex = -1;
  for (int i = 0; i < k; i++) {
    int index = findBestInThisRow(i, k, req);
    if (index != -1) {
      long long cost = calc(i, index, req, k / 2, k / 2);
      if (cost < ans) {
        ans = cost;
        rowIndex = i;
        colIndex = index;
      }
    }
  }
  return {rowIndex, colIndex};
}
int main() {
  long long n, k;
  cin >> n >> k;
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  memset(seats, 0, sizeof(seats));
  for (int i = 0; i < n; i++) {
    pair<long long, long long> p = findBestRowBestPlacement(k, a[i]);
    if (p.first == -1) {
      cout << "-1\n";
    } else {
      cout << p.first + 1 << " " << p.second + 1 << " " << p.second + a[i]
           << "\n";
      for (int i = p.second; i <= p.second + a[i] - 1; i++) {
        seats[p.first][i] = 1;
      }
    }
  }
  return 0;
}
