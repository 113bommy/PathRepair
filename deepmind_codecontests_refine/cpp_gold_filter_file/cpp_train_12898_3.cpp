#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int ret = 0;
    for(int i=0; i<n; ++i){
        long long a;
        cin >> a;
        a = 2 * a + 1;

        bool ng = true;
        for(long long j=2; j*j<=a; ++j){
            if(a % j == 0){
                ng = false;
                break;
            }
        }

        if(ng)
            ++ ret;
    }

    cout << ret << endl;

    return 0;
}