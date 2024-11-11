#include <iostream>
using namespace std;
int main() {
    int n,k,x,y;
    cin>>n>>k>>x>>y;
    cout<<min(k,n)*x+max(n-k,0)*y<<endl;
}
