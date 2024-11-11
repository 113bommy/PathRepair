#include <bits/stdc++.h>
using namespace std;
struct seat {
  int no;
  int width;
  int oc;
  bool operator<(const seat &o) const { return width < o.width; }
};
seat S[200001];
char A[400002];
int P[400002];
int main() {
  priority_queue<seat> Q;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> S[i].width;
    S[i].no = i + 1;
    S[i].oc = 0;
  }
  sort(S, S + n);
  cin >> A;
  int inr = 0, exr = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (A[i] == '0') {
      P[i] = S[inr++].no;
      Q.push(S[inr - 1]);
    } else {
      seat d = Q.top();
      P[i] = d.no;
      Q.pop();
    }
  }
  for (int i = 0; i < 2 * n; i++) cout << P[i] << " ";
  return 0;
}
