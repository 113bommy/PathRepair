#include <bits/stdc++.h>
using namespace std;
int N;
int A[100000 + 1];
int Res;
int Trie[100000 + 1 * 30][2], Count = 0;
void Find() {
  vector<int> Stack;
  Stack.clear();
  for (int i = 1; i <= N; i++) {
    while ((!Stack.empty()) && (A[i] > A[Stack.back()])) {
      Res = max(Res, A[Stack.back()] ^ A[i]);
      Stack.pop_back();
    }
    Stack.push_back(i);
  }
  Stack.clear();
  for (int i = N; i >= 1; i--) {
    while ((!Stack.empty()) && (A[i] > A[Stack.back()])) {
      Res = max(Res, A[Stack.back()] ^ A[i]);
      Stack.pop_back();
    }
    Stack.push_back(i);
  }
}
int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  Res = 0;
  Find();
  cout << Res;
  return 0;
}
