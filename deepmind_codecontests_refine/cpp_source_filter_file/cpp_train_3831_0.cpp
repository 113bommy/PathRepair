#include<iostrem>
#include<string>
using namespace std;
int main()
{
  string s;
  cin>>s;
  if(s=="Sunny") cout<<"Cloudy";
  if(s=="Cloudy") cout<<"Rainy";
  if(s=="Rainy") cout<<"Sunny";
}
  