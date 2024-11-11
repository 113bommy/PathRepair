import math

# for i in range(int(input())):
# n=int(input())
n,k=map(int,input().split())
l=list(map(int,input().split()))
p=[l[0]]
c=1
for i in range(1,n):
    if c<k and l[i] not in p:
        c+=1
        p.insert(0,l[i])
    elif l[i] not in p:
        p.pop()
        p.insert(0,l[i])
print(min(k,c))
print(*p)





