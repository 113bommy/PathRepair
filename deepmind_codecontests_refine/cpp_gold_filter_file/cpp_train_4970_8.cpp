#include <bits/stdc++.h>
using namespace std;
typedef priority_queue<pair<int, int>, vector<pair<int, int> >,
                       greater<pair<int, int> > >
    pq;
long long mod = 1000 * 1000 * 1000 + 7;
bool is_div[110];
int main() {
  long long n;
  cin >> n;
  long long curr_ans = 0;
  long long low = 1, high = n, mid = 0;
  while (low <= high) {
    long long mid = (low + high) / 2;
    long long tot = n;
    long long sum_a = 0;
    for (int i = (1); i < (200); i++) {
      if (tot <= mid) {
        sum_a += tot;
        tot = 0;
      } else {
        sum_a += mid;
        tot -= mid;
        tot -= (tot / 10);
      }
      if (tot == 0) break;
    }
    if (sum_a >= (n + 1) / 2) {
      curr_ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout << curr_ans;
  return 0;
}
