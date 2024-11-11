n=int(input())
neg=0
pos=0
for i in range(n):
    x,y=map(int,input().split())
    if(x<0):
        neg+=1
    else:
        pos+=1
if(pos<=1 or neg<=1):
    print("YES")
else:
    print("NO")
    