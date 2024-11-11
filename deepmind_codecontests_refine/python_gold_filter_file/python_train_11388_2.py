import math


t=int(input())
l=list(map(int,input().split()))
l.sort()
sum=1
count=1
for i in range(1,len(l),1):
    if(l[i]==l[i-1]):
        sum+=1
        if(sum>count):
            count=sum
    else:
        sum=1
if(count<=(t+1)//2):
    print("YES")
else:
    print("NO")
