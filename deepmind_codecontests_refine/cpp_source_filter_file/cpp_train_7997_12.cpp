#include<iostrem>
using namespace std;
int main()
{
    int x,y;
    cin>>x>>y;
    if(x%y)cout<<x;
    else cout<<-1;
    return 0;
}