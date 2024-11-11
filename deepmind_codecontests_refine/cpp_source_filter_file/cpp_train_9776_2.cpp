#include<iostream>
#include<vector>

using namespace std;

int main(){
    while(1){
        int k,sum;
        cin >> k;
        int n = k*(k-1)/2;
        vector<int> c(n);
        if(k==0) break;
        for(int i=0;i<n;i++){
        cin >> c[i];
        sum += c[i];
        }
    cout >> sum/(k-1) >> endl;
    }
}
