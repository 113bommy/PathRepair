n,k=input().split()
n,k=int(n),int(k)
l1=[i for i in input().split()]
x=0
for i in range(n):
    if len(l1[i])==1:
        x+=1
    elif l1[i].count('4')+l1[i].count('7') <= k:
        x+=1
print(x)