# cook your dish here
#import sys
#input=sys.stdin.readline
                           #JAI SHREE RAM #HAR HAR MAHADEV #JAI BAJRANG BALI
m=int(input())
l=list(map(int,input().split()))
s=0
a=0
ans=0
sm=1
if l[0]==1:
    s+=1 
else:
    a+=1
for i in range(1,m):
    if l[i]==1 and l[i-1]==1:
        s+=1
    elif l[i]==2 and l[i-1]==2:
        a+=1
    elif l[i]==2 and l[i-1]==1:
        a=0
        a+=1 
    else:
        s=0
        s+=1 
    ans=min(a,s)
    if 2*ans>sm:
        sm=2*ans
print(sm)