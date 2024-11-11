#include <bits/stdc++.h>
using namespace std;
int n, m;
string k[11] = {"", "", "2", "3", "322", "5", "53", "7", "7222", "7332"};
int size;
string input, output = "";
int main() {
  cin >> size >> input;
  for (int i = 0; i < size; i++) {
    output += k[(int)input[i] - 48];
  }
  sort(output.begin(), output.end());
  reverse(output.begin(), output.end());
  cout << output;
}
