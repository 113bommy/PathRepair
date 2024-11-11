#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <map>

using namespace std;

int crs(double x1, double y1, double x2, double y2) {
    double z = x1*y2-y1*x2;
    return (0 < z ? 1 : (z < 0 ? -1 : 0));
}

bool intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    if (0 <= crs(x2-x1, y2-y1, x3-x1, y3-y1) * crs(x2-x1, y2-y1, x4-x1, y4-y1)) return false;
    if (0 <= crs(x4-x3, y4-y3, x1-x3, y1-y3) * crs(x4-x3, y4-y3, x2-x3, y2-y3)) return false;
    return true;
}

pair<double,double> intersection(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    if (x3 == x4) {
        swap(x1, x3); swap(y1, y3); swap(x2, x4); swap(y2, y4);
    }
    double x, y, a, b, c, d;
    if (x1 == x2) {
        c = (y4-y3)/(x4-x3);
        d = y3-c*x3;
        x = x1;
        y = c*x+d;
    } else {
        a = (y2-y1)/(x2-x1);
        b = y1-a*x1;
        c = (y4-y3)/(x4-x3);
        d = y3-c*x3;
        x = (d-b)/(a-c);
        y = a*x+b;
    }
    return make_pair(x,y);
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        double xa, ya, xb, yb;
        int n;
        cin >> xa >> ya >> xb >> yb >> n;
        bool vertical = fabs(xa-xb) < fabs(ya-yb);

        double xs, ys, xt, yt;
        int o, l;
        vector<pair<double,int> > levels;
        for (int i=0; i<n; ++i) {
            cin >> xs >> ys >> xt >> yt >> o >> l;
            if (intersect(xa, ya, xb, yb, xs, ys, xt, yt)) {
                if (vertical) {
                    double y = intersection(xa, ya, xb, yb, xs, ys, xt, yt).second;
                    levels.push_back(make_pair(y, o==1 ? l : 1-l));
                } else {
                    double x = intersection(xa, ya, xb, yb, xs, ys, xt, yt).first;
                    levels.push_back(make_pair(x, o==1 ? l : 1-l));
                }
            }
        }

        sort(levels.begin(), levels.end());
        int res = 0;
        for (int i=1; i<(int)levels.size(); ++i) {
            if (levels[i].second != levels[i-1].second) {
                res ++;
            }
        }

        cout << res << endl;
    }
    return 0;
}