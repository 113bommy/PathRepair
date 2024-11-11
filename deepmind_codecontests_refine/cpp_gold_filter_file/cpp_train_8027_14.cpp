#include <bits/stdc++.h>
using namespace std;
int arr[100010];
int main() {
  int n, k;
  cin >> n >> k;
  long long int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  if (sum % k == 0) {
    vector<int> v;
    int flag = 0;
    long long int d = sum / k;
    long long int cursum = 0;
    int ind = 1;
    v.push_back(0);
    for (int i = 0; i < n; i++) {
      cursum += arr[i];
      if (cursum == d * ind) {
        ind++;
        v.push_back(i);
      }
    }
    if (ind == k + 1) {
      cout << "Yes" << endl;
      for (int i = 1; i < v.size(); i++) {
        if (i == 1)
          cout << v[i] - v[i - 1] + 1 << " ";
        else
          cout << v[i] - v[i - 1] << " ";
      }
      cout << endl;
    } else {
      cout << "No" << endl;
    }
  } else {
    cout << "No" << endl;
  }
  return 0;
}
