#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    map<pair<int,int>, int> cnt;
    for(int rep = 0; rep < n; ++rep) {
        double x;
        scanf("%lf", &x);
        long long i = llround(x*1e9);
        int two = 0, five = 0;
        while(i % 2 == 0) {
            two++;
            i /= 2;
        }
        while(i % 5 == 0) {
            five++;
            i /= 5;
        }
        ++cnt[{two,five}];
    }
    long long answer = 0;
    for(auto p1 : cnt) {
        for(auto p2 : cnt) {
            if(p1.first.first+p2.first.first >= 18 && p1.first.second+p2.first.second >= 18) {
                if(p1 < p2) {
                    answer += (long long) p1.second  p2.second;
                }
                else if(p1 == p2) {
                    answer += (long long) p1.second * (p1.second - 1) / 2;
                }
            }
        }
    }
    printf("%lld\n", answer);
}