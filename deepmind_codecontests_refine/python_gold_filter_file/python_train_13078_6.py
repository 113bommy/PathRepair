n=int(input())
l=list(map(int,input().split()))
k=360
for i in range(n):
    for j in range(i,n):k=min(k,2*abs(180-sum(l[i:j])))
print(k)