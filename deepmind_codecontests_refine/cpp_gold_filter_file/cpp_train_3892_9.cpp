#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  while (cin >> str) {
    int arr[26] = {0};
    for (int i = 0; i < str.size(); i++) arr[str[i] - 'a']++;
    int c = 0;
    for (int i = 0; i < 26; i++) {
      if (arr[i] % 2) ++c;
    }
    if (c == 0 || c % 2)
      cout << "First\n";
    else
      cout << "Second\n";
  }
}
