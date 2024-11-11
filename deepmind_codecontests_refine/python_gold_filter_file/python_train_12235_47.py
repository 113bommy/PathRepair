import math
n=int(input())
ans=0
for i in range(2*n-2-n+1):
    cur=4
    if(i==1):
        cur*=3
    elif(i>1):
        cur*=3*pow(4,i-1)
    if(i==2*n-2-n-1):
        cur*=3
    elif(i<=2*n-2-n-2):
        cur*=3*pow(4,2*n-2-i-n-1)
    ans+=cur
print(ans)
