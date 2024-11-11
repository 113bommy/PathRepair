#include<iostream>
int main(){
  std::string l[1000];
  int c=0,k;
  while(std::cin>>l[c]) {
    if((l[c].find(","))+(l[c].find("."))!=-2)
      l[c].replace(l[c].length()-1,1,"");
    if( (l[c].length()>2)&&(l[c].length()<7))
      c++;
  }
  for(k=0;k<c;k++) {
    std::cout<<l[k];
    if(k!=c-1) std::cout<<" ";
}
  std::cout<<"\n";
}