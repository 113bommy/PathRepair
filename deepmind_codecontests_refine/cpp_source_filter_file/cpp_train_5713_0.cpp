#include<iostream>
int main(){
  int paper[10][10],x,y,a,max=0;
  std::string s;
  for(x=0; x<10; x++)
    for(y=0; y<10; y++)
      paper[x][y]=0;

  while(std::cin>>s){
    x=s.at(0)-'0';
    y=s.at(2)-'0';
    a=s.at(4)-'0';
      paper[x][y]++;
      if(x>0) paper[x-1][y]++;
      if(x<9) paper[x+1][y]++;
      if(y>0) paper[x][y-1]++;
      if(y<9) paper[x][y+1]++;

    if(a>1){
      if(x>0&&y>0) paper[x-1][y-1]++;
      if(x<9&&y>0) paper[x+1][y-1]++;
      if(x>0&&y<9) paper[x-1][y+1]++;
      if(x<9&&y<9) paper[x+1][y+1]++;
    }
    if(a>2){
      if(x>1)paper[x-2][y]++;
      if(y>1)paper[x][y-2]++;
      if(x<8)paper[x+2][y]++;
      if(y<8)paper[x][y+2]++;
    }
  }

  for(x=0,a=0;x<10;x++)
    for(y=0;y<10;y++){
      paper[x][y]==0 ? a++:,
      paper[x][y]>max ? max=paper[x][y]:;
    }
      std::cout<<a<<"\n"<<max<<"\n";
}