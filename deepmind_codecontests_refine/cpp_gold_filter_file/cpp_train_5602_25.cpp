#include <iostream>

using namespace std;
int a,b;
int main()
{
    cin>>a>>b;
    cout<<max((a+a-1),max((b+b-1),(a+b)));
    return 0;
}
