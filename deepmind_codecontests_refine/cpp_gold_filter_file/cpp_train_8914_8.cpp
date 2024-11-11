#include <bits/stdc++.h>
using namespace std;
struct walrus {
  int age;
  int pos;
};
bool compare(walrus a, walrus b) { return a.age < b.age; }
int main() {
  int n, min, answer[100010];
  vector<walrus> line;
  cin >> n;
  for (int i(0); i < (n); i++) {
    walrus thisone;
    cin >> thisone.age;
    thisone.pos = i;
    line.push_back(thisone);
  }
  stable_sort(line.begin(), line.end(), compare);
  min = -1;
  for (int i(0); i < (n); i++) {
    int val;
    if (line[i].pos > min) {
      min = line[i].pos;
    }
    val = min - line[i].pos - 1;
    if (val < 0) {
      val = -1;
    }
    answer[line[i].pos] = val;
  }
  for (int i(0); i < (n); i++) {
    cout << answer[i] << " ";
  }
}
