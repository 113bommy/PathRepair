numbers=int(input())
lNum=[int(n) for n in input().split()]
cL,suM=[0],sum(lNum)
for i in lNum:
    if i%2==0: cL+=[i]
    if (suM-i)%2==0: cL+=[suM-i]
    if suM%2==0: cL+=[suM]
print(max(cL))