#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int cases;
  cin >> cases;
  while (cases--) {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (auto& k : arr) cin >> k;
    ;
    sort(arr.begin(), arr.end(), greater<int>());
    long int counter = 0;
    long long sum = 0;
    for (auto& k : arr) {
      if (k >= x) {
        sum += k;
        counter++;
      } else {
        sum += k;
        counter++;
        if (not(sum / counter >= x)) {
          counter--;
          break;
        }
      }
    }
    cout << counter << "\n";
    ;
  }
  return 0;
}
