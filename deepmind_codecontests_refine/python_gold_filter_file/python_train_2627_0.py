n=int(input())
b=[int(x) for x in input().split()]
a=[b[0]]
maxi=b[0]
for i in range(1,n):
    if b[i]>=0:
        a.append(b[i]+maxi)
        maxi+=b[i]
    else:
        a.append(b[i]+maxi)
print(*a)