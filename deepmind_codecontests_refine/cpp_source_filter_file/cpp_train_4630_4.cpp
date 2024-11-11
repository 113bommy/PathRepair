#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[5001];
  queue<int> in1;
  queue<int> in2;
  queue<int> in3;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i] = x;
    if (a[i] == 1) {
      in1.push(i + 1);
    } else if (a[i] == 2) {
      in2.push(i + 1);
    } else {
      in3.push(i + 1);
    }
  }
  if (in1.size() == 0 || in2.size() == 0 || in3.size() == 0) {
    cout << "0" << endl;
  } else {
    int mini = min(in1.size(), (in2.size(), in3.size()));
    cout << mini << endl;
    for (int i = 0; i < mini; i++) {
      cout << in1.front() << " " << in2.front() << " " << in3.front() << endl;
      in1.pop();
      in2.pop();
      in3.pop();
    }
  }
  return 0;
}
