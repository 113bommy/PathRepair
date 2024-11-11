#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const int MAX_N = 100005;
vector<int> Tree[MAX_N];
int N, R, C, Lengths[MAX_N], Stack[MAX_N];
string Words[MAX_N];
int SolutionLength, SolutionBeginning;
inline void UpdateSolution(const int beginning, const int length) {
  if (length > SolutionLength) {
    SolutionLength = length;
    SolutionBeginning = beginning;
  }
}
void DFS(const int x) {
  Stack[++Stack[0]] = x;
  UpdateSolution(x, Stack[max(1, Stack[0] - R)] - x);
  for (auto &y : Tree[x]) DFS(y);
  --Stack[0];
}
void Solve() {
  for (int l = 1, r = 1, cost = -1; l <= N; ++l) {
    for (; r <= N && cost + Lengths[r] + 1 <= C; ++r) cost += (Lengths[r] + 1);
    if (l == r)
      DFS(l);
    else
      Tree[r].push_back(l);
    cost -= (Lengths[l] + 1);
  }
  DFS(N + 1);
}
void Read() {
  cin >> N >> R >> C;
  for (int i = 1; i <= N; ++i) {
    cin >> Words[i];
    Lengths[i] = static_cast<int>(Words[i].length());
  }
}
void Print() {
  bool newLine = true;
  for (int i = SolutionBeginning, length = 0;
       i < SolutionBeginning + SolutionLength; ++i) {
    if (newLine) {
      cout << Words[i];
      newLine = false;
      length = Lengths[i];
    } else {
      if (length + Lengths[i] + 1 <= C) {
        cout << " " << Words[i];
        length += Lengths[i];
      } else {
        cout << "\n";
        newLine = true;
        --i;
      }
    }
  }
}
int main() {
  Read();
  Solve();
  Print();
  return 0;
}
