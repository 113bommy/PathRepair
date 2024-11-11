#include <bits/stdc++.h>
using namespace std;
const int kMaxCowSize = 300005;
int berat[kMaxCowSize];
long long mem[600];
long long ret[kMaxCowSize];
int main() {
  int n;
  cin >> n;
  for (int(i) = 0; (i) < (n); ++(i)) {
    int buf;
    scanf("%d", &buf);
    berat[i] = buf;
  }
  vector<pair<pair<int, int>, int> > questions;
  int qn;
  cin >> qn;
  for (int(i) = 0; (i) < (qn); ++(i)) {
    int bufa, bufb;
    cin >> bufa >> bufb;
    --bufa;
    questions.push_back(make_pair(make_pair(bufb, -bufa), i));
  }
  sort(questions.begin(), questions.end());
  int threshold = (int)floor(sqrt(n));
  for (int(i) = 0; (i) < (qn); ++(i)) {
    int b = questions[i].first.first;
    int a = -questions[i].first.second;
    if (b > threshold || i == qn - 1 ||
        (questions[i].first.first != questions[i + 1].first.first)) {
      long long total = 0LL;
      while (a < n) {
        total += (long long)berat[a];
        a += b;
      }
      ret[questions[i].second] = total;
    } else {
      for (int(j) = 0; (j) < (b); ++(j)) mem[i] = 0LL;
      int z = 0;
      int fail = 0;
      for (int j = n - 1; j >= 0; --j) {
        --z;
        if (z < 0) z += b;
        mem[z] += (long long)berat[j];
        while (a == j) {
          ret[questions[i].second] = mem[z];
          ++i;
          if (i == qn || questions[i].first.first != b) {
            fail = 1;
            --i;
            break;
          } else {
            a = -questions[i].first.second;
          }
        }
        if (fail) break;
      }
    }
  }
  for (int(i) = 0; (i) < (qn); ++(i)) {
    assert(ret[i] > 0);
    printf("%lld\n", ret[i]);
  }
  return 0;
}
