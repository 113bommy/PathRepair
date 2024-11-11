n = int(input())
l = list(map(int,input().split()))

ma = max(l)
mi = min(l)

ans = []

if abs(ma) >= abs(mi):
    ind = l.index(ma)
    if ind != 0:
        ans.append([ind+1,1])
        ans.append([ind+1,1])
    for i in range(1,n):
        
        ans.append([i,i+1])
        ans.append([i,i+1])
else:
    ind = l.index(mi)
    if ind != n-1:
        ans.append([ind+1,n])
        ans.append([ind+1,n])
    for i in range(n-2,-1,-1):
        
        ans.append([i+2,i+1])
        ans.append([i+2,i+1])
print(len(ans))
for i in ans:
    print(*i)