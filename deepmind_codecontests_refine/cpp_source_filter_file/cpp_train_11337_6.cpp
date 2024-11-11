#include<iostream>
using namespace std;
int s, b, nS, nB;
int z[101], r[101];
int main(){
    cin >> nS >> nB;
    for(s=1; s<=nS; s++){cin>>z[s];}
    for(b=1; b<=nB; b++){
        for(s=1; s<=nS; s++){
            r[s] = z[s]%b;
        }
        for(s=1; s<=nS-1; s++){
            if(r[s] > r[s+1]){
                swap(z[s], z[s+1]);
                swap(r[s], r[s+1]);
            }
        }
    }
    for(s=1; s<=nS; s++){
        cout << a[s] << endl;
    }
}
void swap(int x, int y){
     int w;
     w = x;
     x = y;
     y = w;
}