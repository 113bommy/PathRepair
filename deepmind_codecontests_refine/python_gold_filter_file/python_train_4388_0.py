cnt = lambda s, i: s.count(i)
ii = lambda: int(input())
si = lambda : input()
f = lambda : map(int,input().split())
il = lambda : list(map(int,input().split()))
n=ii()
l=il()
os=sum(l[1::2])
es=sum(l[2::2])
c=os==es
for i in range(n-1):
    if i&1:
        es+=l[i]-l[i+1]
    else:
        os+=l[i]-l[i+1]
    c+=os==es
print(int(c))