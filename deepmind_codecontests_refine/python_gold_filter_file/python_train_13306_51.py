L = int(input())
r = 0
while 2 ** r <= L:
    r += 1
r -= 1

ans = []
N = r + 1
for i in range(1, N):
    ans.append((i, i + 1, 0))
    ans.append((i, i + 1, 2 ** (i - 1)))
    
for t in range(N - 1, 0, -1):
    if L - 2 ** (t - 1) >= 2 ** r:
        ans.append((t, N, L - 2 ** (t - 1)))
        L -= 2 ** (t - 1)
        
print(N, len(ans))
for i in ans:
    print(i[0], i[1], i[2])