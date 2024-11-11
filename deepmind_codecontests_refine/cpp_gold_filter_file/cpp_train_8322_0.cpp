#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
 
using namespace std;
const double g = 9.8;
const double EPS = 1e-8;
namespace solver{
    int n;
    double v, gx, gy;
    double x1[50], x2[50], y1[50], y2[50];
 
    double calc_y(double vx, double vy, double x){
        double t = x / vx;
        return vy * t - g * t * t / 2;
    }
 
    int sign(double x){
        if(x > EPS) return 1;
        if(x < -EPS) return -1;
        return 0;
    }
     
    int comp(double lb, double ub, double x){
        if(x < lb + EPS) return -1;
        if(x > ub - EPS) return 1;
        return 0;
    }
 
    bool check(double bx, double by){
        double a = g * g / 4.0;
        double b = g * by - v * v;
        double c = bx * bx + by * by;
        double D = b * b - 4 * a * c;
        //printf("D:%f\n", D);
        if(D < 0) return false;
        for(int s = -1; s <= 1; s += 2){
            double tt = (-b + s * sqrt(D)) / (2 * a);
            //printf("tt:%f\n", tt);
            if(tt < 0) continue;
            double t = sqrt(tt);
            double vx = bx / t;
            double vy = (by + g * t * t / 2) / t;
            assert(sign(vx * vx + vy * vy - v * v) == 0);
            double fh = calc_y(vx, vy, gx);
            if(sign(fh - gy) < 0) continue;
            bool ok = true;
            for(int i = 0; i < n; i++){
                if(x1[i] >= gx) continue;
                if(comp(x1[i], x2[i], gx) == 0 && comp(y1[i], y2[i], gy) <= 0 && comp(y1[i], y2[i], fh) >= 0) {
                    ok = false;
                }
                int yl = comp(y1[i], y2[i], calc_y(vx, vy, x1[i]));
                int yr = comp(y1[i], y2[i], calc_y(vx, vy, x2[i]));
                int xh = comp(x1[i], x2[i], vx * vy / g);
                int yh = comp(y1[i], y2[i], calc_y(vx, vy, vx * vy / g));
                if(xh == 0 && yh >= 0 && yl <= 0) ok = false;
                if(yl * yr <= 0) ok = false;
            }
            if(ok) return true;
        }
        return false;
    }
    bool solve(){
        cin >> n;
        cin >> v >> gx >> gy;
        REP(i, n) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        REP(i, n) x2[i] = min(x2[i], gx);
        bool ans = false;
        ans |= check(gx, gy);
        REP(i, n){
            ans |= check(x1[i], y2[i]);
            ans |= check(x2[i], y2[i]);
        }
        return ans;
    }
}
 
int main(){
    cout << (solver::solve() ? "Yes" : "No") << endl;
    return 0;
}
