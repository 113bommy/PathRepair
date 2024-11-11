N,M = map(int, input().split())
a=[input() for i in range(N)]
b=[input() for i in range(M)]
 
ans = 0
for i in range(N-M+1):
    for j in range(N-M+1):
        t = [k[j:j+M] for k in a[i:i+M]]
        if t==b: ans =1
 
print("Yes" if ans else "No")