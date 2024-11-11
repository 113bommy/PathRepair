#print('Hare Krishna')
def I():
    return int(input())
def IL():
    return [int(i) for i in input().split()]
def IM():
    return map(int,input().split())
def IS():
    return input()
n,a,b=IM()
if a>n/2 and b<=n/2 :
    print('Final!')
    exit()
if a<=n/2 and b>n/2:
    print('Final!')
    exit()
cnt=1 
from math import log  
last=log(n)/log(2)
last=int(last)
lo=1 
hi=n
while lo<=hi:
    #curr=[i for i in range(lo,hi+1)]
    z=(lo+hi)//2  
    if (a<=z and b>z) or (a>z and b<=z):
        print(last)
        exit()
    last-=1  
    if a<=z and b<=z :
        hi=z 
    else:
        lo=z+1 
