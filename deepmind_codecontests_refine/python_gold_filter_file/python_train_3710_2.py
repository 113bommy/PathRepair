h,a,c=map(int,input().split())
n,b=map(int,input().split())
from math import ceil
x=ceil(n/a)
h-=b*(x-1)
k=x
kh=0
while h<=0:
    h+=c-b
    kh+=1
print(kh+k)
for i in range(kh):
    print('HEAL')
for i in range(k):
    print('STRIKE')