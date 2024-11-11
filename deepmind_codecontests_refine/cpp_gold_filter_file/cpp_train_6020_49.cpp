#import<iostream>
int main(){std::string s;std::cin>>s;for(int i=0;i<3;i++)std::cout<<(s[i]-'9'?9:1);}