n=int(input())
f=1 
p=[int(i) for i in input().split()]
l=[list(input()) for i in range(n)]
vow="aeiyou"
j=0 
for i in l:
    if sum(z in vow for z in i)!=p[j]:
        f=0 
    j+=1 
if f:
    print('YES')
else:
    print('NO')