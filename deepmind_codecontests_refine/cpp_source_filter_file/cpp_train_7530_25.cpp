#include <bits/stdc++.h>
using namespace std;
int arr[30];
int main() {
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); ++i) arr[str[i] - 'a'] = i + 1;
  int k = 1;
  for (int i = 25; i >= 0; --i) {
    if (k < arr[i])
      for (int j = k - 1; j < arr[i]; ++j)
        if (str[j] == (char)('a' + i)) cout << str[j];
    if (arr[i] > k) k = arr[i];
  }
  cout << endl;
}
