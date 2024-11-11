#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:65000000")
using namespace std;
long long A1 = 137;
int M1 = 10000007;
long long A2 = 1853;
int M2 = 1000000009;
map<int, string> names;
map<pair<int, int>, int> nums;
pair<int, int> hs(char* s) {
  pair<int, int> p(0, 0);
  for (int i = 0; s[i]; ++i) {
    p.first = (p.first * A1 + s[i]) % M1;
    p.second = (p.second * A2 + s[i]) % M2;
  }
  return p;
}
vector<int> graph[10000];
int m;
int n;
char s1[1000], s2[1000];
int getn(pair<int, int> p, char* s) {
  if (nums.find(p) == nums.end()) {
    names[n] = string(s);
    nums[p] = n++;
  }
  return nums[p];
}
short int mas[10000][10000];
void obx(int from, int pos, int glb) {
  if (glb == 2) {
    if (from != pos) ++mas[pos][from];
    return;
  }
  for (int i = 0; i < graph[pos].size(); ++i) obx(from, graph[pos][i], glb + 1);
}
int main() {
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    pair<int, int> a, b;
    int f, t;
    scanf("%s %s", s1, s2);
    a = hs(s1);
    b = hs(s2);
    f = getn(a, s1);
    t = getn(b, s2);
    graph[f].push_back(t);
    graph[t].push_back(f);
  }
  for (int i = 0; i < n; ++i) sort(graph[i].begin(), graph[i].end());
  for (int i = 0; i < n; ++i) obx(i, i, 0);
  printf("%d\n", n);
  for (int i = 0; i < n; ++i) {
    short int answ = 1;
    short int num = 0;
    int curr = 0;
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        while (curr < graph[i].size() && graph[i][curr] < j) ++curr;
        if (curr < graph[i].size() && graph[i][curr] == j) continue;
        if (mas[i][j] == answ) ++num;
        if (mas[i][j] > answ) {
          answ = mas[i][j];
          num = 1;
        }
      }
    }
    printf("%s %d\n", names[i].c_str(), (int)num);
  }
  return 0;
}
