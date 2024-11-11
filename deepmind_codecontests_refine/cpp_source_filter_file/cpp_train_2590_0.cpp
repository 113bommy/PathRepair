#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>
#include <utility>
#include <stack>
#include <string.h>
#include <complex>
using namespace std;

const int INF = 1<<29;
const double EPS = 1e-8;
typedef vector<int> vec;
typedef pair<int,int> P;


int main(){
    while(1){
        double n;
        scanf("%lf",&n);
        if(n<0)break;
        int a = (int)(n * 16);
        if(a>=(1<<12) || a=<(n*16)){
            cout << "NA" << endl;
        }else{
            for(int i=11;i>=0;i--){
                if(i==3) cout << ".";
                cout << ((a>>i)&1);
            }
            cout << endl;
        }
    }

    return 0;
}