#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n;
  vector<int> pos;
  vector<int> neg;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x >= 0)
      pos.push_back(x);
    else
      neg.push_back(x);
  }
  sort(pos.begin(), pos.end());
  if (pos.size() - 1 > 0) {
    cout << 1 << " " << neg[0] << endl;
    cout << pos.size() - 1 << " ";
    for (int i = 1; i < pos.size(); i++) cout << pos[i] << " ";
    cout << endl;
    cout << neg.size() << " " << pos[0] << " ";
    for (int i = 1; i < neg.size(); i++) cout << neg[i] << " ";
    cout << endl;
  } else {
    cout << 1 << " " << neg[0] << endl;
    if ((neg.size() - 1) % 2 == 0) {
      cout << neg.size() - 1 << " ";
      for (int i = 1; i < neg.size(); i++) cout << neg[i] << " ";
      cout << endl;
      cout << 1 << " " << pos[0] << endl;
    } else {
      cout << 2 << " " << neg[1] << " " << neg[2] << endl;
      cout << neg.size() - 3 + 1 << " " << pos[0];
      for (int i = 3; i < neg.size(); i++) cout << neg[i] << " ";
      cout << endl;
    }
  }
}
