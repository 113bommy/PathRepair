#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x, y;
} p[100010], q[4][100010];
int ans[10];
bool cmpx(const Point &a, const Point &b) {
  return a.x == b.x ? a.y < b.y : a.x < b.x;
}
bool cmpy(const Point &a, const Point &b) {
  return a.y == b.y ? a.x < b.x : a.y < b.y;
}
bool cmpl(const Point &a, const Point &b) {
  return a.x + a.y == b.x + b.y ? a.x < b.x : a.x + a.y < b.x + b.y;
}
bool cmpr(const Point &a, const Point &b) {
  return a.x - a.y == b.x - b.y ? a.x < b.x : a.x - a.y < b.x - b.y;
}
bool findlx(const Point *p, int n, const Point &a) {
  int low = 0, high = n - 1, mid;
  while (low <= high) {
    mid = (low + high) >> 1;
    if (p[mid].x == a.x) {
      if (p[mid].y < a.y) return true;
      high = mid - 1;
    } else if (p[mid].x < a.x) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return false;
}
bool findrx(const Point *p, int n, const Point &a) {
  int low = 0, high = n - 1, mid;
  while (low <= high) {
    mid = (low + high) >> 1;
    if (p[mid].x == a.x) {
      if (p[mid].y > a.y) return true;
      low = mid + 1;
    } else if (p[mid].x < a.x) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return false;
}
bool findly(const Point *p, int n, const Point &a) {
  int low = 0, high = n - 1, mid;
  while (low <= high) {
    mid = (low + high) >> 1;
    if (p[mid].y == a.y) {
      if (p[mid].x < a.x) return true;
      high = mid - 1;
    } else if (p[mid].y < a.y) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return false;
}
bool findry(const Point *p, int n, const Point &a) {
  int low = 0, high = n - 1, mid;
  while (low <= high) {
    mid = (low + high) >> 1;
    if (p[mid].y == a.y) {
      if (p[mid].x > a.x) return true;
      low = mid + 1;
    } else if (p[mid].y < a.y) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return false;
}
bool findll(const Point *p, int n, const Point &a) {
  int low = 0, high = n - 1, mid;
  while (low <= high) {
    mid = (low + high) >> 1;
    if (p[mid].x + p[mid].y == a.x + a.y) {
      if (p[mid].x < a.x) return true;
      high = mid - 1;
    } else if (p[mid].x + p[mid].y < a.x + a.y) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return false;
}
bool findrl(const Point *p, int n, const Point &a) {
  int low = 0, high = n - 1, mid;
  while (low <= high) {
    mid = (low + high) >> 1;
    if (p[mid].x + p[mid].y == a.x + a.y) {
      if (p[mid].x > a.x) return true;
      low = mid + 1;
    } else if (p[mid].x + p[mid].y < a.x + a.y) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return false;
}
bool findlr(const Point *p, int n, const Point &a) {
  int low = 0, high = n - 1, mid;
  while (low <= high) {
    mid = (low + high) >> 1;
    if (p[mid].x - p[mid].y == a.x - a.y) {
      if (p[mid].x < a.x) return true;
      high = mid - 1;
    } else if (p[mid].x - p[mid].y < a.x - a.y) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return false;
}
bool findrr(const Point *p, int n, const Point &a) {
  int low = 0, high = n - 1, mid;
  while (low <= high) {
    mid = (low + high) >> 1;
    if (p[mid].x - p[mid].y == a.x - a.y) {
      if (p[mid].x > a.x) return true;
      low = mid + 1;
    } else if (p[mid].x - p[mid].y < a.x - a.y) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return false;
}
int main() {
  int n, m, cur, i;
  while (~scanf("%d %d", &n, &m)) {
    for (i = 0; i < m; ++i) {
      scanf("%d %d", &p[i].x, &p[i].y);
      q[0][i] = q[1][i] = q[2][i] = q[3][i] = p[i];
    }
    sort(q[0], q[0] + m, cmpx);
    sort(q[1], q[1] + m, cmpy);
    sort(q[2], q[2] + m, cmpl);
    sort(q[3], q[3] + m, cmpr);
    memset(ans, 0, sizeof(ans));
    for (i = 0; i < m; ++i) {
      cur = 0;
      if (findlx(q[0], m, p[i])) ++cur;
      if (findrx(q[0], m, p[i])) ++cur;
      if (findly(q[1], m, p[i])) ++cur;
      if (findry(q[1], m, p[i])) ++cur;
      if (findll(q[2], m, p[i])) ++cur;
      if (findrl(q[2], m, p[i])) ++cur;
      if (findlr(q[3], m, p[i])) ++cur;
      if (findrr(q[3], m, p[i])) ++cur;
      ++ans[cur];
    }
    for (i = 0; i < 8; ++i) printf("%d ", ans[i]);
    printf("%d\n", ans[i]);
  }
  return 0;
}
