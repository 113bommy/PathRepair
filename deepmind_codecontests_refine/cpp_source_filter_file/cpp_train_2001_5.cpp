#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  string str;
  cin >> str;
  int arr[26] = {0};
  int mx = 0;
  vector<int> v;
  for (int i = 0; i < str.length(); i++) {
    int temp = str[i] - 'a';
    arr[temp] = 1;
    for (int i = temp + 1; i < 26; i++)
      arr[temp] = max(arr[temp], (arr[i] + 1));
    mx = max(arr[temp], mx);
    v.push_back(arr[temp]);
  }
  cout << mx << endl;
  for (int i = 0; i < v.size(); i++) cout << v[i];
}
