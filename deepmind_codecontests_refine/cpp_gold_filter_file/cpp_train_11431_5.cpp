#include <iostream>
using namespace std;
int main() {
    int k,x; cin>>k>>x;
    int i,u=x-(k-1),l=x+(k-1);
    for(i=u;i<=l;i++) cout<<i<<" ";
}