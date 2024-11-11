t=int(input())
for tt in range(t):
    a,b,c,d,k = map(int,input().split())
    x=0;y=0
    if a%c==0:
        x=a//c
    else:
        x=a//c+1
    
    if b%d==0:
        y=b//d
    else:
        y=b//d+1
        
    if(x+y<=k):
        print(x,y)
    else:
        print(-1)
