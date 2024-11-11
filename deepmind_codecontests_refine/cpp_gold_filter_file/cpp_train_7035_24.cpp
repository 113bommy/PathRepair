#include <bits/stdc++.h>
using namespace std;
bool bcompare(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }
int main() {
  string A, B, aux;
  int C;
  cin >> A >> B;
  vector<int> myv;
  for (int iA = 0; iA < A.length(); iA++) {
    cin >> C;
    myv.push_back(C);
  }
  int r = myv.size(), l = 0, mid, answer = 0;
  bool work;
  while (l < r) {
    work = false;
    mid = l + (r - l) / 2;
    aux = A;
    for (int iA = 0; iA < mid; iA++) {
      aux[myv[iA] - 1] = ' ';
    }
    for (int iA = 0, iB = 0; iA < aux.size(); iA++) {
      if (aux[iA] == B[iB]) {
        iB++;
      }
      if (iB == B.size()) {
        work = true;
        break;
      }
    }
    if (work && answer < mid) {
      answer = mid;
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  cout << answer << endl;
  return 0;
}
