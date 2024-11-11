#include<iostream>
#include<vector>

using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b, a%b);
}

int main(){

    int p, q;
    cin>> p>> q;

    q=q/gcd(p, q);
    vector<int> v;
    for(int i=2; i*<=q; i++){
        if(q%i==0){
            v.push_back(i);
            while(q%i==0) q/=i;
        }
    }
    int r=1;
    for(int i=0; i<v.size(); i++) r*=v[i];

    cout<< r<< endl;

    return 0;
}