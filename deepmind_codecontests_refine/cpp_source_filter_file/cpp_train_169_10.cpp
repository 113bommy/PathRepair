#include <bits/stdc++.h>
using namespace std;
typedef struct two_pair {
  int num;
  string src;
} two_pair;
void IsInVector(vector<two_pair> &list_pair, string pair);
int main() {
  string s, pair;
  int n;
  two_pair max{0, ""};
  vector<two_pair> num_two_gram;
  char car[2];
  cin >> n;
  cin >> s;
  for (int i = 0; i < n - 1; i++) {
    pair = "";
    car[0] = s[i];
    car[1] = s[i + 1];
    pair.push_back(car[0]);
    pair.push_back(car[1]);
    IsInVector(num_two_gram, pair);
  }
  for (two_pair p : num_two_gram) {
    if (p.num > max.num) {
      max = {p.num, p.src};
    }
  }
  cout << max.src;
  return 0;
}
void IsInVector(vector<two_pair> &list_pair, string pair) {
  for (two_pair &p : list_pair) {
    if (!(pair.compare(p.src))) {
      p.num += 1;
      return;
    }
  }
  two_pair aux{0, pair};
  list_pair.push_back(aux);
  return;
}
