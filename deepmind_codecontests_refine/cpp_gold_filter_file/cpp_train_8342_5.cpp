#include <bits/stdc++.h>
using namespace std;
void build(int *arr, int n) {
  for (int i = n - 1; i > 0; i--) arr[i] = arr[i << 1] + arr[i << 1 | 1];
}
void modify(int *arr, int p, int value, int n) {
  for (arr[p += n] = value; p > 1; p >>= 1) arr[p >> 1] = arr[p] + arr[p ^ 1];
}
int query(int *arr, int l, int r, int n) {
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += arr[l++];
    if (r & 1) res += arr[--r];
  }
  return res;
}
void print(int *arr, int n) {
  int counter = 1;
  for (int i = 1; i < (n << 1); i++) {
    cout << arr[i] << " ";
    if ((i + 1) % counter == 0) {
      cout << endl;
      counter *= 2;
    }
  }
}
int main() {
  int n, N;
  cin >> n;
  N = n << 1;
  int *arr = new int[N];
  for (int i = 0; i < n; i++) cin >> arr[i];
  map<int, vector<pair<int, int>>> segs;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j >= 0; j--) {
      sum += arr[j];
      segs[sum].push_back({j, i});
    }
  }
  vector<pair<int, int>> res;
  int resbest = 0;
  for (const auto &p : segs) {
    const vector<pair<int, int>> &pp = p.second;
    vector<pair<int, int>> blocks;
    int counter = 0;
    int r = -1;
    for (auto seg : pp) {
      if (seg.first > r) {
        counter++;
        blocks.push_back(seg);
        r = seg.second;
      }
    }
    if (counter > resbest) {
      resbest = counter;
      res = blocks;
    }
  }
  cout << resbest << endl;
  for (auto seg : res) {
    cout << seg.first + 1 << " " << seg.second + 1 << endl;
  }
  return 0;
}
