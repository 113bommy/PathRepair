input();A=map(int,input().split());C=[0]*99;D=0
for a in A:a//=400;D+=a>7;C[a]=a<8
E=sum(C);print(max(E,1),E+D)