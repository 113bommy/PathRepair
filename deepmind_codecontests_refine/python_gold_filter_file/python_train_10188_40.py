n=int(input())
l=[int(i) for i in input().split()]

b=[]
for i in range(n):
    b.append(22000*i+1)

a=b[:]
b.reverse()

for i in range(1,n):
    a[l[i]-1]+=i
print(*a)
print(*b)
