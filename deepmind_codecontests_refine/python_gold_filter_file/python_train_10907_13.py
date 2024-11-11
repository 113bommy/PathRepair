import sys
x,k,d=map(int,input().split())

x=abs(x)

a=x//d

if a>=k:
    ans=x-k*d

elif (k-a)%2==0:
    ans=x-d*a

else:
    ans=x-d*a-d

print(abs(ans))