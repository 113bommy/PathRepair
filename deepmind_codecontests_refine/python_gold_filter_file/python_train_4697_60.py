l=list(map(int,input().split()))
l.sort()
if l[0]+l[1]<=l[2]:
    print(l[2]-l[1]-l[0]+1)
else:
    print(0)
