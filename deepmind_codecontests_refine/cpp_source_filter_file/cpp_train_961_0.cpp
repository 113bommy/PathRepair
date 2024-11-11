#include <bits/stdc++.h>
using namespace std;
int freq[1000001] = {0};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      freq[arr[i]]++;
    }
    for (int i = 0; i < n; i++) {
      if (i > 0)
        if (arr[i] > i + 1 || arr[i] < arr[i - 1]) {
          cout << "-1";
          exit(0);
        } else if (arr[i] > i + 1 || arr[i] < arr[i - 1]) {
          cout << "-1";
          exit(0);
        }
    }
    int ind;
    if (arr[0] == 0) {
      ind = 1;
      while (freq[ind] != 0) ind++;
      cout << ind << " ";
      ind++;
    } else {
      ind = 1;
      while (freq[ind] != 0) ind++;
      cout << ind << " ";
      ind++;
    }
    freq[arr[0]]--;
    for (int i = 1; i < n; i++) {
      if (freq[arr[i - 1]] == 0) {
        cout << arr[i - 1] << " ";
        if (ind == arr[i - 1]) ind++;
      } else {
        while (freq[ind] != 0) {
          ind++;
        }
        cout << ind << " ";
        ind++;
      }
      freq[arr[i]]--;
    }
  }
}
