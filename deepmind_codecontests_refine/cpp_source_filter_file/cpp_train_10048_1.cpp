#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000 + 5;
pair<long long, long long> Points[MAX];
int O[MAX];
void fail() { cout << "fail!!!" << '\n'; }
bool compare(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first < b.first;
}
bool compare1(int a, int b) { return Points[a].first < Points[b].first; }
bool compare2(int a, int b) { return Points[a].first > Points[b].first; }
long long MaxY[MAX][2], MinY[MAX][2];
int N;
long long pow2(long long a) { return a * a; }
bool inside(int s, int m, int value) {
  if (value >= N) {
    return false;
  }
  bool condA = pow2(Points[value].first - Points[s].first) <= m;
  bool condB = abs(Points[s].first) >= abs(Points[value].first);
  bool conditions = condA and condB;
  return conditions;
}
bool valid(long long m) {
  if (pow2(Points[N - 1].first - Points[0].first) <= m) {
    return true;
  }
  if (pow2(MaxY[N][0] - MinY[N][0]) <= m) {
    return true;
  }
  for (int s = 0; s < N; s++) {
    int a = s;
    int b = N;
    while (a + 1 != b) {
      int half = (a + b) / 2;
      if (inside(s, m, half)) {
        a = half;
      } else {
        b = half;
      }
    }
    int e = a;
    int max_y = max(MaxY[s][0], MaxY[e + 1][1]);
    int min_y = min(MinY[s][0], MinY[e + 1][1]);
    long long d1 = max_y - min_y;
    d1 = pow2(d1);
    long long d2 = pow2(max_y) + pow2(Points[s].first);
    long long d3 = pow2(min_y) + pow2(Points[s].first);
    if (d1 <= m and d2 <= m and d3 <= m) {
      return true;
    }
  }
  return false;
}
long long BinarySearch() {
  long long A = -1;
  long long B = LLONG_MAX;
  while (A + 1 != B) {
    long long half = (A + B) / 2;
    if (valid(half)) {
      B = half;
    } else {
      A = half;
    }
  }
  return B;
}
void show() {
  cout << "[";
  for (int i = 0; i <= N; i++) {
    cout << MaxY[i][0];
    if (i != N) {
      cout << ',';
    }
  }
  cout << "]\n";
  cout << "[";
  for (int i = 0; i <= N; i++) {
    cout << MinY[i][0];
    if (i != N) {
      cout << ',';
    }
  }
  cout << "]\n";
}
void MakeSP() {
  MaxY[0][0] = LLONG_MIN;
  MinY[0][0] = LLONG_MAX;
  MaxY[N][0] = LLONG_MIN;
  MinY[N][0] = LLONG_MAX;
  for (int x = 0; x < N; x++) {
    int y = N - x - 1;
    MaxY[x + 1][0] = max(MaxY[x][0], Points[x].second);
    MinY[x + 1][0] = min(MinY[x][0], Points[x].second);
    MaxY[y][1] = max(MaxY[y + 1][1], Points[y].second);
    MinY[y][1] = min(MinY[y + 1][1], Points[y].second);
  }
}
void Swap() {
  for (int i = 0; i < N; i++) {
    swap(Points[i].first, Points[i].second);
  }
}
void List() {
  cout << "list = " << '\n';
  for (int i = 0; i < N; i++) {
    cout << Points[i].first << ' ' << Points[i].second << '\n';
  }
  cout << "----------" << '\n';
}
void Invert() {
  for (int i = 0; i < N; i++) {
    Points[i] = pair<long long, long long>(-Points[i].first, Points[i].second);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    long long x, y;
    cin >> x >> y;
    Points[i] = pair<long long, long long>(x, y);
  }
  sort(Points, Points + N, compare);
  MakeSP();
  long long a1 = BinarySearch();
  Invert();
  sort(Points, Points + N, compare);
  MakeSP();
  long long a2 = BinarySearch();
  cout << min(a1, a2) << '\n';
}
