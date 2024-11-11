from bisect import *
s,b = map(int,input().split())
spaceships=list(map(int,input().split()))
bases = []
for x in range(b):
    bases.append(list(map(int,input().split())))
bases.sort(key = lambda x:x[0])
val =bases[0][1]
for i in range(1,b):
    bases[i][1]+=val
    val = bases[i][1]
defence,gold=map(list,zip(*bases))
for i in spaceships:
    index = bisect_right(defence,i)-1
    if index<0:
        print(0,end=" ")
        continue
    print(gold[index],end=" ")
