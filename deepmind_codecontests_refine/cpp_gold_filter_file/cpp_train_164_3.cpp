#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int main() {
  long long ax, ay, bx, by, cx, cy;
  scanf("%I64d %I64d %I64d %I64d %I64d %I64d", &ax, &ay, &bx, &by, &cx, &cy);
  long long ab = ((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
  long long bc = ((cx - bx) * (cx - bx) + (cy - by) * (cy - by));
  if (ab == bc && ((ax - bx) * (cy - by) != (ay - by) * (cx - bx)))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
