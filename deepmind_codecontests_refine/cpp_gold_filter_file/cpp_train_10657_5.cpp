#include <bits/stdc++.h>
using namespace std;
typedef struct edge {
  int a;
  int b;
  int c;
};
int n, m;
edge roads[10000];
vector<int> out[200];
double matrix[200][200];
double const eps = 1e-10;
double val[200];
bool isZero(double r) { return r < eps && r > -eps; }
void flip(int r1, int r2) {
  for (int i = 1; i <= n; i++) {
    double fill = matrix[r1][i];
    matrix[r1][i] = matrix[r2][i];
    matrix[r2][i] = fill;
  }
}
void scale(int r1, double c) {
  for (int i = 1; i <= n; i++) {
    matrix[r1][i] *= c;
  }
}
void add(int r1, int r2, double c) {
  for (int i = 1; i <= n; i++) {
    matrix[r1][i] += matrix[r2][i] * c;
  }
}
void solve_system() {
  for (int cur = 2; cur <= n - 1; cur++) {
    int i;
    for (i = cur; i <= n - 1; i++) {
      if (!isZero(matrix[i][cur])) {
        swap(i, cur);
        break;
      }
    }
    if (i == n) continue;
    scale(cur, 1 / matrix[cur][cur]);
    for (int j = cur + 1; j <= n - 1; j++) {
      if (!isZero(matrix[j][cur])) {
        add(j, cur, -matrix[j][cur]);
      }
    }
  }
  for (int cur = n - 1; cur >= 2; cur--) {
    if (isZero(matrix[cur][cur]))
      continue;
    else {
      val[cur] = -matrix[cur][1];
    }
    for (int j = cur - 1; j >= 2; j--) {
      add(j, cur, -matrix[j][cur]);
    }
  }
}
void set_up() {
  for (int i = 0; i < 200; i++) {
    val[i] = 0;
    for (int j = 0; j < 200; j++) {
      matrix[i][j] = 0;
    }
  }
  val[1] = 1;
  for (int i = 2; i <= n - 1; i++) {
    matrix[i][i] = out[i].size();
    for (int j = 0; j < out[i].size(); j++) {
      matrix[i][out[i][j]] -= 1;
    }
  }
}
void print_mat() {
  for (int i = 2; i <= n - 1; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%f ", matrix[i][j]);
    }
    printf("\n");
  }
}
int main() {
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &roads[i].a, &roads[i].b, &roads[i].c);
    out[roads[i].a].push_back(roads[i].b);
    out[roads[i].b].push_back(roads[i].a);
  }
  set_up();
  solve_system();
  double scale = 1e10;
  for (int i = 0; i < m; i++) {
    double dif = val[roads[i].a] - val[roads[i].b];
    if (isZero(dif))
      continue;
    else {
      scale = min(scale, abs(roads[i].c / dif));
    }
  }
  double total = 0;
  for (int i = 0; i < out[1].size(); i++) {
    total += val[1] - val[out[1][i]];
  }
  printf("%.10f\n", total * scale);
  for (int i = 0; i < m; i++) {
    double dif = val[roads[i].a] - val[roads[i].b];
    printf("%.10f\n", scale * dif);
  }
}
