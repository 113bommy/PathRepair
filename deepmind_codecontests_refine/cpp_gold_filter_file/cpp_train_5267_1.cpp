#include <bits/stdc++.h>
using namespace std;
char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                    'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                    's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int main() {
  int n, k;
  cin >> n >> k;
  vector<string> names(50);
  char c = 'A';
  string temp;
  for (int i = 0; i < 26; i++) names[i] = c++;
  c = 'A';
  for (int i = 26; i < 50; i++) {
    names[i] = c;
    names[i] += tolower(c++);
  }
  for (int i = 0; i < n - k + 1; i++) {
    cin >> temp;
    if (temp == "NO") names[i + k - 1] = names[i];
  }
  for (int i = 0; i < n; i++) cout << names[i] << " ";
  return 0;
}
