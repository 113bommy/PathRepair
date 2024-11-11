l=[int(i) for i in input().split()]
l.sort()
if l[0]+l[1]>l[2]:
    print(0)
else:
    print(l[2]-l[0]-l[1]+1)
