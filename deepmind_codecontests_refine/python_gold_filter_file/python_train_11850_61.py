import math 
N,M=map(int,input().split())
a=M//N
ans=0
for i in range(1,int(math.sqrt(M))+1):
    if M%i==0:
        if i<=a and i>ans:ans=i
        if M//i<=a and M//i>ans:ans=M//i
print(ans)