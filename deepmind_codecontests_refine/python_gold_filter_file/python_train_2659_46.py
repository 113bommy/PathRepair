q=[int(x) for x in input().split()]
n,h=q[0],q[1]
b=[]
a= [int(x) for x in input().split()]
for i in range(n):
    if a[i]<=h:
        b.append(1)
    else:
        b.append(2)
print(sum(b))
