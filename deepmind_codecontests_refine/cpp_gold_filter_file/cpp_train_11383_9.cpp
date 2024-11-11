#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long int arr[n];
  vector<long long int> count;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n - 1; i++) {
    long long int highestpower = log2(n - i - 1);
    count.push_back(arr[i]);
    long long int index = i + pow(2, highestpower);
    arr[index] = arr[index] + arr[i];
  }
  for (int i = 1; i < n - 1; i++) {
    count[i] = count[i] + count[i - 1];
  }
  for (int i = 0; i < n - 1; i++) {
    cout << count[i] << " ";
  }
}
