#include <bits/stdc++.h>
int main(int argc, char *argv[]) {
  std::vector<std::string> p;
  std::string s, t;
  std::ios_base::sync_with_stdio(false);
  std::cin >> s >> t;
  struct edit {
    size_t c;
    char o;
  };
  struct plan {
    size_t rows, cols;
    std::vector<edit> m;
    plan(const size_t rows, const size_t cols)
        : rows(rows), cols(cols), m(rows * cols) {}
    edit &operator()(const size_t r, const size_t c) { return m[c + r * cols]; }
  } w(s.length() + 1, t.length() + 1);
  w(0, 0) = {0, '_'};
  for (size_t r = 1; r <= s.length(); r++) w(r, 0) = {r, 'D'};
  for (size_t c = 1; c <= t.length(); c++) w(0, c) = {c, 'I'};
  for (size_t r = 1; r <= s.length(); r++)
    for (size_t c = 1; c <= t.length(); c++) {
      const edit del = {1 + w(r - 1, c).c, 'D'};
      const edit ins = {1 + w(r, c - 1).c, 'I'};
      const edit sub = {(s[r - 1] != t[c - 1]) + w(r - 1, c - 1).c,
                        s[r - 1] != t[c - 1] ? 'S' : 'K'};
      w(r, c) = del.c <= ins.c && del.c <= sub.c   ? del
                : ins.c <= del.c && ins.c <= sub.c ? ins
                                                   : sub;
    }
  printf("%" PRId64 "\n", static_cast<int64_t>(w(s.length(), t.length()).c));
  for (ssize_t r = s.length(), c = t.length(); r >= 0 && c >= 0;
       w(r, c).o == 'D'   ? r--
       : w(r, c).o == 'I' ? c--
                          : (r--, c--)) {
    char b[32] = "";
    if (w(r, c).o == 'I')
      sprintf(b, "INSERT %" PRId64 " %c", static_cast<int64_t>(c), t[c - 1]);
    else if (w(r, c).o == 'D')
      sprintf(b, "DELETE %" PRId64, static_cast<int64_t>(c + 1));
    else if (w(r, c).o == 'S')
      sprintf(b, "REPLACE %" PRId64 " %c", static_cast<int64_t>(c), t[c - 1]);
    if (b[0] != '\0') p.push_back(b);
  }
  for (std::vector<std::string>::const_reverse_iterator i = p.crbegin();
       i != p.crend(); ++i)
    printf("%s\n", i->c_str());
  return EXIT_SUCCESS;
}
