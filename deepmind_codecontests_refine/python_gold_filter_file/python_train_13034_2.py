from functools import reduce
t=int(input())
while(t):
    t-=1
    n=int(input())
    *a,=map(int, input().split())
    x=reduce(lambda x,y: x^y, a)
    s=sum(a)
    print(2)
    print(x, s+x)