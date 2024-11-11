from math import ceil
a1,a2,a3=map(int,input().split())
b1,b2,b3=map(int,input().split())
n=int(input())
s1=a1+a2+a3
s2=b1+b2+b3
s=ceil(s1/5)+ceil(s2/10)
if s>n:
    print("NO")
else:
    print("YES")