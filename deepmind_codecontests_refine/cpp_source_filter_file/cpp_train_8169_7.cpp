#include <bits/stdc++.h>
using namespace std;
string outputAtRight(vector<int> str) {
  vector<char> output(0);
  for (int i = 0; i < str.size() - 1; i++) {
    output.push_back('(');
    output.push_back((str[i] == 0) ? '0' : '1');
    output.push_back('-');
    output.push_back('>');
  }
  output.push_back((str[str.size() - 1] == 0) ? '0' : '1');
  for (int i = 0; i < str.size() - 1; i++) {
    output.push_back(')');
  }
  return string(output.begin(), output.end());
}
int main() {
  int n;
  cin >> n;
  vector<int> input(n, 0);
  for (int i = 0; i < n; i++) cin >> input[i];
  if (input[n - 1] == 1) {
    cout << "NO\n";
    return 0;
  }
  if (n == 1) {
    cout << "YES\n0\n";
    return 0;
  }
  if (n == 2 && input[0] == 0) {
    cout << "NO\n";
    return 0;
  }
  if (input[n - 2] == 1) {
    cout << "YES\n";
    cout << outputAtRight(vector<int>(input.begin(), input.end() - 1))
         << "->0\n";
    return 0;
  }
  if (input[n - 3] == 0) {
    cout << "YES\n";
    cout << outputAtRight(vector<int>(input.begin(), input.end() - 1))
         << "->0\n";
    return 0;
  } else {
    int index = n - 3;
    while (index >= 0 && input[index] == 1) index--;
    if (index == -1) {
      cout << "N0\n";
      return 0;
    }
    cout << "YES\n";
    cout << outputAtRight(vector<int>(input.begin(), input.end() - 1))
         << "->0\n";
  }
  return 0;
}
