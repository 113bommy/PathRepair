#include <bits/stdc++.h>
using namespace std;
vector<long long int> v;
int n;
long long int f() {
  long long int sum = 0;
  for (int i = (0); i < (n); i++) {
    for (int j = (i); j < (n); j++) {
      long long int menor = 0x3f3f3f3f3f3f3f3fLL;
      for (int l = (i); l <= (j); l++) {
        menor = min(menor, v[l]);
      }
      sum += menor;
    }
  }
  return sum;
}
vector<pair<long long int, vector<long long int> > > vres;
bool cmp(pair<long long int, vector<long long int> > a,
         pair<long long int, vector<long long int> > b) {
  return a.first > b.first;
  if (a.first > b.first)
    return 1;
  else if (b.first > a.first)
    return 0;
  for (int i = (0); i < (a.second.size()); i++) {
    if (a.second[i] < b.second[i]) return 1;
    if (a.second[i] > b.second[i]) return 0;
  }
  return 0;
}
int main(int argc, char const* argv[]) {
  int m;
  scanf("%d %d", &n, &m);
  for (int i = (0); i < (n); i++) v.push_back(i + 1);
  long long int sum;
  vector<long long int> v2;
  do {
    sum = f();
    v2 = v;
    vres.push_back(make_pair(sum, v2));
  } while (next_permutation(v.begin(), v.end()));
  sort(vres.begin(), vres.end(), cmp);
  if (0)
    for (int i = (0); i < (vres.size()); i++) {
      printf("w: %I64d \n", vres[i].first);
    }
  v2.clear();
  v2 = vres[m - 1].second;
  for (int i = (0); i < (v2.size()); i++) {
    printf("%I64d", v2[i]);
    if (i != v2.size() - 1) printf(" ");
  }
  printf("\n");
  return 0;
}
