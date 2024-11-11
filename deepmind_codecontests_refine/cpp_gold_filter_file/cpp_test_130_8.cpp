#include <bits/stdc++.h>
using namespace std;
int arr[20001];
bool ASK(int A, int B, int C) {
  if (A == B || A == C) return (arr[A] == -1 ? 0 : 1);
  cout << "? " << A + 1 << ' ' << B + 1 << ' ' << C + 1 << endl;
  bool F;
  cin >> F;
  return F;
}
int32_t main() {
  cin.tie(0), iostream::sync_with_stdio(0);
  int testcases, n;
  cin >> testcases;
  while (testcases--) {
    cin >> n;
    for (int i = 0; i < n; i++) arr[i] = 0;
    vector<int> RES, BAD;
    for (int i = 0; i < n / 3; i++) {
      RES.push_back(ASK(i * 3, i * 3 + 1, i * 3 + 2));
    }
    int A = 0, B = 0;
    for (int i = 0; i < n / 3; i++) {
      if (RES[i])
        A = i;
      else
        B = i;
    }
    bool F1 = ASK(A * 3, A * 3 + 1, B * 3),
         F2 = ASK(A * 3, A * 3 + 1, B * 3 + 1);
    if (F1 & F2) {
      arr[A * 3] = arr[A * 3 + 1] = 1;
      F1 = ASK(A * 3, B * 3, B * 3 + 1), F2 = ASK(A * 3, B * 3 + 1, B * 3 + 2);
      if (F1 && F2)
        arr[B * 3] = arr[B * 3 + 2] = -1;
      else if (F1)
        arr[B * 3 + 1] = arr[B * 3 + 2] = -1;
      else if (F2)
        arr[B * 3] = arr[B * 3 + 1] = -1;
      else
        arr[B * 3] = arr[B * 3 + 1] = arr[B * 3 + 2] = -1;
    } else {
      if (!F1 && !F2)
        arr[B * 3] = -1, arr[B * 3 + 1] = -1;
      else if (!F1)
        arr[B * 3] = -1, arr[B * 3 + 2] = -1;
      else
        arr[B * 3 + 2] = -1, arr[B * 3 + 1] = -1;
      int Z;
      if (arr[B * 3] == -1)
        Z = B * 3;
      else
        Z = B * 3 + 1;
      F1 = !ASK(Z, A * 3, A * 3 + 1), F2 = !ASK(Z, A * 3 + 1, A * 3 + 2);
      if (F1 && F2)
        arr[A * 3] = arr[A * 3 + 2] = 1;
      else if (F1)
        arr[A * 3 + 1] = arr[A * 3 + 2] = 1;
      else if (F2)
        arr[A * 3] = arr[A * 3 + 1] = 1;
      else
        arr[A * 3] = arr[A * 3 + 1] = arr[A * 3 + 2] = 1;
    }
    int BB, GG;
    for (int i = 0; i < n; i++)
      if (arr[i] == -1)
        BB = i;
      else if (arr[i] == 1)
        GG = i;
    for (int i = 0; i < n / 3; i++) {
      if (RES[i]) {
        int X = ASK(BB, i * 3, i * 3 + 1), Y = ASK(BB, i * 3 + 1, i * 3 + 2);
        if (X && Y)
          arr[i * 3] = arr[i * 3 + 1] = arr[i * 3 + 2] = 1;
        else if (!X && !Y)
          arr[i * 3] = arr[i * 3 + 2] = 1, arr[i * 3 + 1] = -1;
        else if (!X)
          arr[i * 3] = -1, arr[i * 3 + 1] = arr[i * 3 + 2] = 1;
        else
          arr[i * 3] = arr[i * 3 + 1] = 1, arr[i * 3 + 2] = -1;
      } else {
        bool X = !ASK(GG, i * 3, i * 3 + 1), Y = !ASK(GG, i * 3 + 1, i * 3 + 2);
        if (X && Y)
          arr[i * 3] = arr[i * 3 + 1] = arr[i * 3 + 2] = -1;
        else if (!X && !Y)
          arr[i * 3] = arr[i * 3 + 2] = -1, arr[i * 3 + 1] = 1;
        else if (!X)
          arr[i * 3] = 1, arr[i * 3 + 1] = arr[i * 3 + 2] = -1;
        else
          arr[i * 3] = arr[i * 3 + 1] = -1, arr[i * 3 + 2] = 1;
      }
    }
    vector<int> ANS;
    for (int i = 0; i < n; i++)
      if (arr[i] == -1) ANS.push_back(i + 1);
    cout << "! " << ANS.size() << ' ';
    for (int i = 0; i < ANS.size(); i++) cout << ANS[i] << ' ';
    cout << endl;
  }
}
