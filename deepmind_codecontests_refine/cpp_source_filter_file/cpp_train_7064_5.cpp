#include<string>
main(){char c[];scanf("%s",c);std::string s(c);puts(s.find(70,s.find(67))!=-1?"Yes":"No");}