n=int(input())
x=[int(item) for item in input().split()]
checklist=[]
for item in range(1,n):
    checklist.append(x[item]-x[item-1])
D=max(checklist)
anslist=[]
for item in range(1,n-1):
    if x[item+1]-x[item-1]>D:
        anslist.append(x[item+1]-x[item-1])
    else:
        pass
if len(anslist)==n-2:
    print(min(anslist))
else:
    print(D)