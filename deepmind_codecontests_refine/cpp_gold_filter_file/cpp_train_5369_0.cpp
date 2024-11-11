#include <bits/stdc++.h>
struct operation {
  char c;
  int k;
};
static int find(const char grid[6][6], const char c) {
  for (int i = 0; i < 36; i++)
    if (grid[i / 6][i % 6] == c) return i;
  return -1;
}
static void shc(std::vector<operation> &o, char grid[6][6], const int c,
                int d) {
  for (const int s = d > 0 ? -1 : 1; d != 0; d += s) {
    o.push_back({d < 0 ? 'U' : 'D', c});
    for (int r = 0; r < 5; r++)
      std::swap(grid[(6 + r * s) % 6][c], grid[(7 + r * s) % 6][c]);
  }
}
static void shr(std::vector<operation> &o, char grid[6][6], const int r,
                int d) {
  for (const int s = d > 0 ? -1 : 1; d != 0; d += s) {
    o.push_back({d < 0 ? 'L' : 'R', r});
    for (int c = 0; c < 5; c++)
      std::swap(grid[r][(6 + c * s) % 6], grid[r][(7 + c * s) % 6]);
  }
}
static void swp(std::vector<operation> &o, char grid[6][6], const int i,
                const int j,
                void (*sha)(std::vector<operation> &o, char grid[6][6],
                            const int i, int d),
                void (*shb)(std::vector<operation> &o, char grid[6][6],
                            const int i, int d)) {
  sha(o, grid, j + 1, 1);
  shb(o, grid, i + 0, 1);
  sha(o, grid, j + 1, 1);
  shb(o, grid, i + 0, -1);
  sha(o, grid, j + 1, 1);
  shb(o, grid, i + 0, 1);
  sha(o, grid, j + 1, 1);
  shb(o, grid, i + 0, -1);
  sha(o, grid, j + 1, 1);
  shb(o, grid, i + 0, 1);
  sha(o, grid, j + 1, 1);
  shb(o, grid, i + 0, -1);
  sha(o, grid, j + 1, 1);
}
static void swh(std::vector<operation> &o, char grid[6][6], const int r,
                const int c) {
  swp(o, grid, r, c, shc, shr);
}
static void swv(std::vector<operation> &o, char grid[6][6], const int r,
                const int c) {
  swp(o, grid, c, r, shr, shc);
}
int main(int argc, char *argv[]) {
  char grid[6][6] = {};
  for (int i = 0, c = getchar(); i < 36 && c != EOF; c = getchar())
    if (('0' <= c && c <= '9') || ('A' <= c && c <= 'Z')) {
      grid[i / 6][i % 6] = c;
      i++;
    }
  if (grid[5][5] == '\0') {
    fprintf(stderr, "Grid IO error.\n");
    return EXIT_FAILURE;
  }
  std::vector<operation> o;
  for (int r = 0; r < 6; r++)
    for (int c = 0; c < 6; c++) {
      const char e = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[c % 6 + r * 6];
      if (grid[r][c] != e) {
        int i = find(grid, e), x = i % 6, y = i / 6;
        if (i == -1) return EXIT_FAILURE;
        while (c < x) swh(o, grid, y, --x);
        while (c > x) swh(o, grid, y, x++);
        while (r < y) swv(o, grid, --y, x);
        while (r > y) swv(o, grid, y++, x);
      }
    }
  printf("%d\n", static_cast<int>(o.size()));
  for (const operation &i : o) printf("%c%d\n", i.c, i.k + 1);
  return EXIT_SUCCESS;
}
