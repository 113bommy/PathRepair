t=int(input())
while t:
    n=int(input())
    l=list(map(int,input().split()))
    l.sort()
    l.pop(len(l)-1)
    a=l.pop(len(l)-1)
    if a>len(l):
        print(len(l))
    else:
        print(a-1)
    t=t-1