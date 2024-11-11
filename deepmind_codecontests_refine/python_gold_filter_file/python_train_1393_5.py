n=int(input())
a=[int(i) for i in input().split()]
p=sum(a)
l=0
for ll in range(1,6):
    k=p+ll
    if k%(n+1)!=1:
        l+=1
print(l)
