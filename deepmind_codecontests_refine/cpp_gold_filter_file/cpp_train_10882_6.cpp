#include <bits/stdc++.h>
void print(std::vector<long long> const &input) {
  for (long long i = 0; i < input.size(); i++) {
    std::cout << input.at(i) << ' ';
  }
}
using namespace std;
int arr[1000010];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  long long temp, i;
  for (i = 1; i <= n; i++) {
    cin >> temp;
    if (temp < 1000010) arr[temp] = 1;
  }
  long long sum = 0;
  vector<long long> ans;
  for (i = 1; i < 1000010; i++) {
    if (arr[i] == 0) {
      sum += i;
      if (sum <= m)
        ans.push_back(i);
      else {
        break;
      }
    }
  }
  sum += i;
  while (sum <= m) {
    ans.push_back(i);
    i++;
    sum += i;
  }
  cout << ans.size() << endl;
  print(ans);
  cout << endl;
  return 0;
}
