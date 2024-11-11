//Name: Find the Outlier
//Level: 
//Category:
//Note:

/**
 */
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool solve() {
    int N;
    cin >> N;
    if(!N) return false;

    vector<double> ys(N+3);
    for(int i = 0; i < N+3; ++i) {
        cin >> ys[i];
    }
    const int CHECKER = N+2;
    int candidate = CHECKER;
    for(int outlier = 0; outlier <= N+1; ++outlier) {
        double c = 0;
        // term for generate f(i)
        for(int i = 0; i <= N+1; ++i) {
            if(i == outlier) continue;
            double tmp = 1;
            for(int j = 0; j <= N+1; ++j) {
                if(j == i || j == outlier) continue;
                tmp *= static_cast<double>(CHECKER - j) / (i - j);
            }
            c += tmp * ys[i];
        }
        //cout << c << ' ' << ys[CHECKER] << endl;
        if(fabs(c - ys[CHECKER]) < 0.9) {
            candidate = outlier;
            break;
        }
    }
    cout << candidate << endl;
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    while(solve()) ;
    return 0;
}