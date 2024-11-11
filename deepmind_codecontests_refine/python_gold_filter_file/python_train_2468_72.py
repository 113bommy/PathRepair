n=int(input())
l=[int(x) for x in input().split()]
k=0
while len(l)>1:
    i=l.index(min(l)) if k%2 else l.index(max(l))
    del l[i]
    k=1-k
print(l[0])