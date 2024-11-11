n = int(input())
p = list(map(int,input().split()))
i = 1
res = 0
while i < n+1:
    if p[i-1] == i:
        res += 1
        i += 1
    i += 1
print(res)