import math
L=lambda:list(map(int,input().split()))
M=lambda:map(int,input().split())
I=lambda:int(input())
n,k=M()
if k>=n:
    print(-1)
    exit()
a=[1]
x=0
for i in range(2,n+1):
    if x==k:
        a.append(i+1)
    else:
        a.append(i)
        x+=1
b=set(a)
for i in range(1,n+1):
    if i not in b:
        a[0]=i
        a[-1]=1
        break
print(*a)
    
