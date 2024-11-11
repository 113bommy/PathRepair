#include <bits/stdc++.h>
using namespace std;
long long int arr[100005], dp[1000005], res[100005];
bool vis[100005];
vector<long long int> group;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long int n, temp, temp2, min1;
  bool flag = false;
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    cin >> temp >> temp2;
    if (temp != temp2) return cout << "rated", 0;
    if (temp > min1) flag = true;
    min1 = min(temp, min1);
  }
  if (flag) return cout << "unrated", 0;
  cout << "maybe", 0;
  return 0;
}
