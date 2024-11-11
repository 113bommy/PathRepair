#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const double inf = 1e18;
double x[N], y[N];
double dx[N], dy[N];
int n;

double f(double a) {
    double minx = inf, maxx = -inf, miny = inf, maxy = -inf;
    for (int i = 0; i < n; i++) { //n个点
        double nx = x[i] + a * dx[i];
        double ny = y[i] + a * dy[i];
        minx = min(minx, nx);
        maxx = max(maxx, nx);
        miny = min(miny, ny);
        maxy = max(maxy, ny);
    }
    return (maxx - minx) * (maxy - miny);
}

double ternary_search(double l, double r) {
   double ans = inf;
  int times = 300;
    while (times--) {
        double m1 = l + (r - l) / 3;
         double m2 = r - (r - l) / 3;
        //double m1 = (l*2+r) / 3;
        //double m2 = (r*2+l) / 3;
        double f1 = f(m1);
        double f2 = f(m2);
        ans = min(ans, f1);
         ans = min(ans, f2);
        if (f1 < f2) r = m2;
        else l = m1;
    }
    return ans;
}

int main() {
   // while (cin >> n) {
      cin>>n;
        //memset(dx, 0, sizeof(dx));
        //memset(dy, 0, sizeof(dy));

        string s;
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i] >> s;
            if (s == "R") dx[i] = 1;
            if (s == "L") dx[i] = -1;
            if (s == "U") dy[i] = 1;
            if (s == "D") dy[i] = -1;
        }


       // cout << fixed << setprecision(11) <<ternary_search(0, 1e9) << endl;
      printf("%f\n",ternary_search(0, 1e9));
   // }

    return 0;
}