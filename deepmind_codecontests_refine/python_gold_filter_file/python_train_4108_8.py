from collections import Counter
l=int(input())
c=Counter(map(int,input().split()))
s=max(c)+1
f=[0,c[1]]
for i in range(2,s):
    d=i%2
    f[d]=max(f[1-d],f[d]+c[i]*i)
print(max(f))
