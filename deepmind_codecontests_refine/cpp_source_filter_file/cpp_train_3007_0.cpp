g#include <iostream>
#include <set>
#include <cstring>
using namespace std;

int n;
int main() {
    while (cin >> n, n != 0) {
        set<int> mod;
        for (int i = 1; i < n; i++) 
            mod.insert( (i*i) % n );

        int count[(n-1)/2+1];
        memset(count, 0, sizeof(count));
        for (set<int>::iterator si = mod.begin();
                si != mod.end(); si++) {
            for (set<int>::iterator sj = mod.begin();
                    sj != mod.end(); sj++) {
                if (*si == *sj) continue;
                int dif = *si - *sj;
                if (dif < 0) dif += n;
                if (dif > (n-1)/2) dif = n - dif;
                count[dif]++;
            }
        }

        for (int i = 1; i <= (n-1)/2; i++) 
            cout << count[i] << endl;
    }   
    return 0;
}