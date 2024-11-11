#7/4/19
#1119A
#BlueyNeilo

n=int(input())
c=list(map(int,input().split()))

if c[0]!=c[n-1]:
    print(n-1)
else:
    init = c[0]
    lo = 1
    hi = n-2
    while c[lo]==init: lo+=1
    while c[hi]==init: hi-=1
    print(max(hi,n-1-lo))
    