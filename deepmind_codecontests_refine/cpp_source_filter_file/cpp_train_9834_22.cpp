#include <bits/stdc++.h>
using namespace std;
void border() { cout << "+------------------------+" << endl; }
int myrow[4] = {5, 6, 0, 7};
void line_out(int row, int k) {
  cout << "|";
  if (row == 3) {
    for (int j = 1; j <= 24; j++) {
      if (k >= 3 && j == 1)
        cout << "0";
      else if (k < 3 && j == 1)
        cout << "#";
      else
        cout << '.';
    }
    cout << '|' << endl;
    return;
  }
  for (int j = 0; j < 22; j++) {
    int index = ceil((double)(j + 1) / 2);
    int diff = (row == 4) ? 3 : 4;
    int value = myrow[row - 1] - diff;
    if (index > 1) value = myrow[row - 1] + 3 * (index - 2);
    string result = ((j + 1) % 2 == 0) ? "." : ((k >= value) ? "0" : "#");
    cout << result;
  }
  cout << "|";
  if (row == 1) {
    cout << "D";
  } else {
    cout << ".";
  }
  cout << "|";
  if (row == 1 || row == 4) cout << ")";
  cout << endl;
}
int main(int argc, char** argv) {
  int k;
  cin >> k;
  border();
  for (int i = 1; i <= 4; i++) line_out(i, k);
  border();
  return 0;
}
