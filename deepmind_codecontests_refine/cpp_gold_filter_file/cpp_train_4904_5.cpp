#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long int n, i;
  cin >> n;
  vector<long int> ans1, ans2;
  for (i = 0; i < n; i++) {
    if ((i + 1) % 2 == 0)
      ans1.push_back(i + 1);
    else
      ans2.push_back(i + 1);
  }
  if (n == 1 || n == 2)
    cout << "No";
  else {
    cout << "Yes" << endl;
    cout << ans1.size() << " ";
    for (i = 0; i < ans1.size(); i++) cout << ans1[i] << " ";
    cout << endl;
    cout << ans2.size() << " ";
    for (i = 0; i < ans2.size(); i++) cout << ans2[i] << " ";
  }
  return 0;
}
