#include <bits/stdc++.h>
using namespace std;
char str[100];
struct Range {
  Range(int _start, int _len, int _id) : start(_start), len(_len), id(_id) {}
  int start, len;
  int id;
};
list<Range> ranges;
int main() {
  int nQ, size;
  while (scanf("%d%d", &nQ, &size) == 2) {
    ranges.clear();
    int nextId = 1;
    for (int q = 0; q < nQ; ++q) {
      scanf("%s", str);
      if (strcmp(str, "alloc") == 0) {
        int want;
        scanf("%d", &want);
        list<Range>::iterator itr = ranges.begin();
        int start = 0;
        bool success = false;
        while (itr != ranges.end()) {
          int free = itr->start - start;
          if (free >= want) {
            ranges.insert(itr, Range(start, want, nextId));
            success = true;
            break;
          }
          start = itr->start + itr->len;
          ++itr;
        }
        if (!success && size - start >= want) {
          success = true;
          ranges.push_back(Range(start, want, nextId));
        }
        if (success)
          printf("%d\n", nextId++);
        else
          puts("NULL");
      } else if (strcmp(str, "erase") == 0) {
        int target;
        scanf("%d", &target);
        bool found = false;
        for (list<Range>::iterator itr = ranges.begin(); itr != ranges.end();
             ++itr) {
          if (itr->id == target) {
            ranges.erase(itr);
            found = true;
            break;
          }
        }
        if (!found) puts("ILLEGAL_ERASE_ARGUMENT");
      } else {
        int start = 0;
        for (list<Range>::iterator itr = ranges.begin(); itr != ranges.end();
             ++itr) {
          itr->start = start;
          start = itr->start + itr->len;
        }
      }
    }
  }
}
