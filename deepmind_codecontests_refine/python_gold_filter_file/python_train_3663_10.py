n = int(input())
l = list(map(int,input().split()))
k = sorted(l)[::-1]
p = [[i,[j for j in range(n) if l[j]==i]] for i in set(k)]
x=0
p = sorted(p)[::-1]
for i in range(n):
    x+=k[i]*i+1
k=[]
for i in p:
    k+=[j+1 for j in i[1]] 
print(x)
print(*k)