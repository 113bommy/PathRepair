#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    a.push_back(s.length());
  }
  cin >> s;
  int temp = s.length();
  sort(a.begin(), a.end());
  int count = 0;
  int count1 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < temp) {
      count++;
    } else if (a[i] == temp) {
      count1++;
    } else {
      break;
    }
  }
  cout << count + ((count / k) * 5) + 1 << " ";
  cout << count + count1 + (((count + count1) / k) * 5);
  return 0;
}
