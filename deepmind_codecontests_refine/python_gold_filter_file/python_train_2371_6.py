n = int(input())
l = sorted(map(int,input().split()))

ans = 0

for a in range(n):
    for b in range(a+1,n):
        for c in range(b+1,n):
            if  l[a] != l[b] != l[c] and l[a]+l[b] > l[c]:
                ans += 1
print(ans)