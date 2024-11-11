#include <bits/stdc++.h>
using namespace std;
typedef struct {
  int p;
  int e;
} person;
int n, k;
vector<person> personList;
int length_vector;
int flag = 0;
int min_cost;
vector<int> result;
vector<int> cumulative_cost_to_win_all;
int min(int a, int b) {
  if (a < b) return a;
  return b;
}
inline bool myfunction(person a, person b) {
  return ((a.e + a.p) < (b.e + b.p));
}
typedef struct {
  int a;
  int b;
} mapa;
map<int, mapa> mymap;
void calculate(int index, int points, int cost) {
  mapa ma;
  ma.a = points;
  ma.b = cost;
  if (mymap.find(index) != mymap.end()) {
    if (mymap[index].a <= points && mymap[index].b >= cost) {
      return;
    }
  } else {
    mymap[index] = ma;
  }
  if (flag == 1 && cost > min_cost) {
    return;
  }
  if (index > length_vector) {
    return;
  }
  if (index == (length_vector)) {
    int pos = 1;
    for (int i = 0; i < length_vector; i++) {
      if (result[i] == 0) {
        if (points <= (personList[i].p + 1)) pos++;
      } else if (result[i] == 1) {
        if (points < personList[i].p) pos++;
      }
    }
    if (pos <= k) {
      if (flag == 0) {
        flag = 1;
        min_cost = cost;
      } else if (flag == 1) {
        min_cost = min(min_cost, cost);
      }
    }
  } else {
    int rank = 1;
    for (int i = 0; i < index; i++) {
      if (result[i] == 0) {
        if ((points + (n - index)) <= (personList[i].p + 1)) {
          rank++;
        }
      } else {
        if ((points + (n - index)) < personList[i].p) rank++;
      }
    }
    for (int i = index; i < n; i++) {
      if ((points + (n - index)) < personList[i].p) rank++;
    }
    if (rank > k) {
      return;
    } else {
      result[index] = 0;
      for (int i = (index + 1); i < n; i++) {
        result[i] = 0;
      }
      calculate(index + 1, points, cost);
      result[index] = 1;
      for (int i = (index + 1); i < n; i++) {
        result[i] = 0;
      }
      calculate(index + 1, points + 1, cost + personList[index].e);
    }
  }
}
int main() {
  scanf("%d %d", &n, &k);
  personList.resize(n);
  result.resize(n);
  length_vector = personList.size();
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &personList[i].p, &personList[i].e);
    result[i] = 0;
  }
  sort(personList.begin(), personList.end(), myfunction);
  calculate(0, 0, 0);
  if (flag == 0)
    printf("-1");
  else
    printf("%d", min_cost);
}
