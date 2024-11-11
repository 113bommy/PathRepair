#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

const double EPS = 1.0e-9;
const double INF = 1.0e20;

int dsign(double d) {
    if (fabs(d) < EPS) {
        return 0;
    } else {
        return d < 0 ? -1 : 1;
    }
}

struct Point {
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {
    }

    bool operator<(const Point& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

double dist(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

struct BiTSP {
    int n;
    vector<vector<double>> memo;
    vector<vector<double>> d;
    
    double solve(vector<Point>& points, int n) {
        this->n = n;
        sort(points.begin(), points.end());
        
        d.assign(n, vector<double>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = dist(points[i], points[j]);
            }
        }
        memo.assign(n, vector<double>(n, -1));
        return search(0, 0);
    }

    double search(int i, int j) {
        if (i < j) {
            return search(j, i);
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        double result = INF;
        if (i == n - 1) {
            result = d[j][n - 1]; 
        }
        else {
            result = min(search(i + 1, j) + d[i][i + 1], search(i, i + 1) + d[j][i + 1]); 
        }
        memo[i][j] = result;
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<Point> a;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back(Point(x, y));
    }
    BiTSP tsp;
    double ans = tsp.solve(a, n);

    cout << fixed << setprecision(9) << ans << endl;

    return 0;
}