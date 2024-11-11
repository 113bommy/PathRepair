#include <bits/stdc++.h>
using namespace std;
const int maxn = 30000;
vector<int> seq1;
vector<int> seq2;
int a[maxn + 10];
int d1, d2, n;
bool finish = false;
void print() {
  for (int i = 0; i < seq1.size(); i++) {
    cout << seq1[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < seq2.size(); i++) {
    cout << seq2[i] << " ";
  }
  finish = true;
}
void f2(int x) {
  if (finish) {
    return;
  }
  if (x == n + 1) {
    print();
    return;
  }
  if (seq1.back() + d1 == a[x]) {
    seq1.push_back(a[x]);
    f2(x + 1);
    seq1.pop_back();
  }
  if (seq2.back() + d2 == a[x]) {
    seq2.push_back(a[x]);
    f2(x + 1);
    seq2.pop_back();
  }
}
void f1(int x) {
  if (finish) {
    return;
  }
  if (x == n + 1) {
    print();
    return;
  }
  if (d1 + seq1.back() == a[x]) {
    seq1.push_back(a[x]);
    f1(x + 1);
    seq1.pop_back();
  }
  seq2.push_back(a[x]);
  d2 = seq2[1] - seq2[0];
  f2(x + 1);
  seq2.pop_back();
}
void f3(int x) {
  if (finish) {
    return;
  }
  if (x == n + 1) {
    cout << a[0] << " " << a[1];
    cout << endl;
    for (int i = 2; i <= n; i++) {
      cout << a[i] << " ";
    }
    finish = true;
    return;
  }
  if (d1 + seq1.back() == a[x]) {
    seq1.push_back(a[x]);
    f3(x + 1);
    seq1.pop_back();
  }
  seq2.push_back(a[x]);
  f1(x + 1);
  return;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (n == 2) {
    cout << a[1] << endl << a[2];
    return 0;
  }
  seq1.push_back(a[1]);
  seq1.push_back(a[2]);
  d1 = a[2] - a[1];
  f3(3);
  if (finish) {
    return 0;
  }
  seq1.clear();
  seq2.clear();
  seq1.push_back(a[1]);
  seq1.push_back(a[3]);
  d1 = a[3] - a[1];
  seq2.push_back(a[2]);
  f1(4);
  if (finish) {
    return 0;
  }
  seq1.clear();
  seq2.clear();
  seq1.push_back(a[2]);
  seq1.push_back(a[3]);
  seq2.push_back(a[1]);
  d1 = a[3] - a[2];
  f1(4);
  if (finish) {
    return 0;
  }
  cout << "No solution";
  return 0;
}
