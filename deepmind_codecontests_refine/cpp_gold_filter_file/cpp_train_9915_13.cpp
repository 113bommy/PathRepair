#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
using ii = pair<long long int, long long int>;
class prioritize {
 public:
  bool operator()(ii &p1, ii &p2) { return p1.first < p2.first; }
};
auto start_time = high_resolution_clock::now();
void time() { return; }
void ojudge() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  return;
}
int main() {
  ojudge();
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    vector<long long int> arr(n + 1, 0), peak(n + 1, 0);
    for (long long int i = 1; i < n + 1; i++) cin >> arr[i];
    for (long long int i = 2; i < n; i++) {
      if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) peak[i] = 1;
      peak[i] += peak[i - 1];
    }
    long long int ind = 1, num = 0;
    for (long long int i = 1; i + k - 1 <= n; i++) {
      long long int val = peak[i + k - 2] - peak[i];
      if (val > num) {
        num = val;
        ind = i;
      }
    }
    cout << num + 1 << " " << ind << "\n";
  }
  time();
  return 0;
}
