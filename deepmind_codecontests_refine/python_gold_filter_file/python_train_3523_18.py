import itertools
h,w=map(int,input().split())
n=int(input())
a=list(map(int,input().split()))

l=list(itertools.chain.from_iterable([[i+1]*a[i] for i in range(n)]))
c=0
for i in range(h):
    if c%2==0:
      print(*l[i*w:(i+1)*w])
    else:
      print(*(l[(i+1)*w-1:i*w-1:-1]))
    c+=1
