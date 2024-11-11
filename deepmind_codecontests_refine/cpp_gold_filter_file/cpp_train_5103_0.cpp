#include<iostream>
#include<cmath>
using namespace std;
struct Circle { double x, y, r; };
int main() {
    Circle p, q;
    cin >> p.x >> p.y >> p.r;
    cin >> q.x >> q.y >> q.r;
    double dist = sqrt((p.x - q.x)*(p.x - q.x) + (p.y - q.y)*(p.y - q.y));
    if (dist > p.r + q.r)cout << "4" << endl;
    else if (dist == p.r + q.r) {
        cout << "3" << endl;
    }
    else if (p.r <= q.r) {
        if (p.r + dist == q.r)cout << "1" << endl;
        if (p.r + dist < q.r)cout << "0" << endl;
        if (p.r + dist > q.r)cout << "2" << endl;
    }
    else {
        if (q.r + dist == p.r)cout << "1" << endl;
        if (q.r + dist < p.r)cout << "0" << endl;
        if (q.r + dist > p.r)cout << "2" << endl;
    }
    return 0;
}