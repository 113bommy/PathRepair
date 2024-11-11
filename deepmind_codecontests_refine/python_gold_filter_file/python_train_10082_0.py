n = int(input())
As = list(map(int, input().split()))
ret = []
for a in range(n-1, 0-1, -2):
    ret.append(As[a])
for a in range(n%2, n-1, 2):
    ret.append(As[a])
print(' '.join(map(str,ret)))
