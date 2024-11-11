#include <bits/stdc++.h>
using namespace std;
int isPrime[1000005];
void pre() {
  for (long long int i = 2; i < 1000005; i++) isPrime[i] = 1;
  for (long long int i = 2; i < 1000005; i++)
    if (isPrime[i]) {
      for (long long int j = i * i; j < 1000005; j += i) isPrime[j] = 0;
    }
}
vector<int> prefix;
int firstOccurence(int val) {
  if (prefix[prefix.size() - 1] < val) return -1;
  int start = 0, end = prefix.size() - 1, mid;
  while (start <= end) {
    mid = (start + end) / 2;
    if (prefix[mid] < val) start = mid + 1;
    if (prefix[mid] == val) {
      if (mid == 0) return mid;
      if (prefix[mid - 1] != val)
        return mid;
      else
        end = mid - 1;
    }
    if (prefix[mid] > val) end = mid - 1;
  }
}
int main(void) {
  int i, j, a, b, l, ans = 0, k;
  pre();
  cin >> a >> b >> k;
  for (i = 1; i < a; i++) isPrime[i] = 0;
  prefix.push_back(0);
  for (i = 1; i <= b; i++) prefix.push_back(prefix[i - 1] + isPrime[i]);
  for (i = a; i <= b; i++) {
    int idx;
    if (isPrime[i] == 0)
      idx = firstOccurence(prefix[i] + k);
    else
      idx = firstOccurence(prefix[i] + k - 1);
    if (idx > 0) ans = max(ans, idx - i + 1);
  }
  if (ans == 0)
    cout << "-1";
  else {
    int remainingElements = b - a + 1;
    for (i = b; i >= a; i--) {
      if (i - ans < a) break;
      if (i - ans <= a && prefix[i] - prefix[i - ans] < k) {
        ans++;
        i--;
      }
    }
    cout << ans;
  }
  return 0;
}
