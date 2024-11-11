#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const int MAX_VALUE = 10000;
vector<int> Values;
int N;
int BestCost, BestH, BestR;
void Solve() {
  sort(Values.begin(), Values.end());
  BestCost = oo;
  BestH = BestR = 0;
  for (int ratio = 0; ratio <= MAX_VALUE; ++ratio) {
    int minV = Values[0], maxV = Values[0];
    for (int i = 1; i < N; ++i) {
      minV = min(minV, Values[i] - i * ratio);
      maxV = max(maxV, Values[i] - i * ratio);
    }
    int h = (minV + maxV) / 2;
    int cost = max(h - minV, maxV - h);
    if (cost < BestCost) {
      BestCost = cost;
      BestH = h;
      BestR = ratio;
    }
  }
}
void Read() {
  cin >> N;
  Values = vector<int>(N);
  for (int i = 0; i < N; ++i) cin >> Values[i];
}
void Print() { cout << BestCost << "\n" << BestH << " " << BestR << "\n"; }
int main() {
  Read();
  Solve();
  Print();
  return 0;
}
