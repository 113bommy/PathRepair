#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <iomanip>

using ll = long long;

using namespace std;

using P = pair<double, double>;

int main() {
    int n;
    cin >> n;
    P en[n];
    for (auto &ei:en) cin >> ei.first >> ei.second;
    double best = 0;
    for (int i=0; i<1000; i++) {
        double theta = 2 * M_PI * i / 1000000;
        double x = cos(theta), y = sin(theta),
        P sum = {0, 0};
        for (auto &ei:en)
            if (x * ei.first + y * ei.second > 0) {
                sum.first += ei.first;
                sum.second += ei.second;
            }
        best = max(best, hypot(sum.first, sum.second));
    }
    cout << setprecision(15) << best << '\n';
    return 0;
}