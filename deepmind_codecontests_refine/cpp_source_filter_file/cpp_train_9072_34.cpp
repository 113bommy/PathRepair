#include <bits/stdc++.h>
using namespace std;
long long arr[100001], read[200001], total[200001];
stack<pair<long long, long long> > st;
int main() {
  long long n, p, x, y;
  cin >> n;
  stack<pair<long long, long long> > st;
  if (n - 1 == 0) {
    cout << 1 << endl;
    cout << 1 << " " << 1 << endl;
  } else {
    if (n % 2 == 0) {
      p = (n / 2) + 1;
      x = n / 2;
      y = x;
    } else {
      p = (n / 2) + 2;
      x = n / 2;
      y = x + 1;
    }
    long long i = 1, j = 1;
    cout << p << endl;
    while (y--) {
      cout << i << " " << j << endl;
      j++;
    }
    i = p, j = p;
    while (x--) {
      st.push(make_pair(i, j));
      j--;
    }
    while (!st.empty()) {
      cout << st.top().first << " " << st.top().second << endl;
      st.pop();
    }
  }
}
