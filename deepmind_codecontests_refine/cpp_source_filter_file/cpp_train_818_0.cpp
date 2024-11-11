#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<numeric>
using namespace std;
 
const double PI = 3.14159265358979;
 
class Point {
public:
    double x, y;
    Point(double x = 0.0, double y = 0.0) :x(x), y(y) {}
};
 
class Wind {
public:
    double w, a;
};
 
bool include(double angle, double low, double high) {
    if(low < 0.0) {
        double l = low + 2.0 * PI;
        if(l <= angle) return true;
    }
    if(high > 2.0 * PI) {
        double h = high - 2.0 * PI;
        if(angle <= h) return true;
    }
    return low <= angle && angle <= high;
}
 
bool savor(const Point &home, const Wind &wind, const vector<Point> &blossom, double d) {
    d /= 2.0;
    for(const auto &b: blossom) {
        Point dif(home.x - b.x, home.y - b.y);
        double angle = atan2(dif.y, dif.x);
        double dist = hypot(dif.y, dif.x);
        if(angle < 0.0) angle = angle + 2.0 * PI;
        if(dist <= wind.a + EPS && include(angle, wind.w - d, wind.w + d)) return true;
    }
    return false;
}
 
double toRadian(double d) {
    return d * PI / 180.0;
}
 
int main() {
    int H, R;
    while(cin >> H >> R, H | R) {
        vector<Point> home(H);
        for(auto &i: home) cin >> i.x >> i.y;
 
        int U, M, S;
        double du, dm, ds;
        cin >> U >> M >> S >> du >> dm >> ds;
 
        du = toRadian(du);
        dm = toRadian(dm);
        ds = toRadian(ds);
 
        vector<Point> plum(U), peach(M), cherry(S);
        for(auto &i: plum) cin >> i.x >> i.y;
        for(auto &i: peach) cin >> i.x >> i.y;
        for(auto &i: cherry) cin >> i.x >> i.y;
 
        vector<Wind> wind(R);
        for(auto &i: wind) cin >> i.w >> i.a;
        for(auto &i: wind) i.w = toRadian(i.w);
 
        // solve
        vector<int> number(H, 0);
        int maxNumber = 0;
 
        for(int i = 0; i < H; ++i) {
            for(int day = 0; day < R; ++day) {
                bool ok = savor(home[i], wind[day], {Point(0.0, 0.0)}, du);
                bool ng = false;
                ng |= savor(home[i], wind[day], plum, du);
                ng |= savor(home[i], wind[day], peach, dm);
                ng |= savor(home[i], wind[day], cherry, ds);
 
                if(!ok || ng) continue;
 
                ++number[i];
                maxNumber = max(maxNumber, number[i]);
            }
        }
 
        if(maxNumber) {
            bool first = true;
            for(int i = 0; i < H; ++i) if(number[i] == maxNumber) {
                if(!first) cout << " ";
                first = false;
                cout << i + 1;
            }
            cout << endl;
        } else {
            cout << "NA" << endl;
        }
    }
}