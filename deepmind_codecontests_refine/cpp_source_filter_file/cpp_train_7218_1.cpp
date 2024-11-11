#include <bits/stdc++.h>
using namespace std;
string input, output;
int err;
void getData() {
  if (cin >> input) {
    output.append(input);
    if (!input.compare("pair")) {
      output.append("<");
      getData();
      output.append(",");
      getData();
      output.append(">");
    }
  } else {
    err = 1;
  }
}
int main() {
  cin >> input;
  getData();
  if (err == 1 || cin >> input) {
    cout << "Error occured" << endl;
  } else {
    cout << output << endl;
  }
}
