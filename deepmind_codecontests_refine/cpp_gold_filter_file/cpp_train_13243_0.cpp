#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  long long int ans = 0;
  cin >> n >> k;
  unordered_map<string, int> h;
  string str;
  vector<string> arr;
  for (int i = 0; i < n; i++) {
    cin >> str;
    arr.push_back(str);
    h[str]++;
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      string temp;
      for (int p = 0; p < k; p++) {
        if (arr[i][p] == arr[j][p])
          temp += arr[i][p];
        else if ('T' != arr[i][p] && 'T' != arr[j][p])
          temp += "T";
        else if ('S' != arr[i][p] && 'S' != arr[j][p])
          temp += "S";
        else
          temp += "E";
      }
      h[arr[i]]--;
      h[arr[j]]--;
      ans = ans + h[temp];
      h[arr[i]]++;
      h[arr[j]]++;
    }
  }
  cout << ans / 3 << endl;
}
