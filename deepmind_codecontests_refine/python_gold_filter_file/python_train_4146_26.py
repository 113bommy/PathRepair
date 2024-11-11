from collections import defaultdict
n = int(input())
a = list(map(int,input().split()))
a.sort(key=lambda x:-x)
d = defaultdict(int)
for i in a:
    d[i] += 1
beki = [2**i for i in range(32,0,-1)]
ans = 0
for i in a:
    if d[i] == 0:
        continue
    for j in beki:
        if j <= i:
            break
        ni = j - i
        if ni == i:
            if d[i] >= 2:
                ans +=1
                d[i]-=2
                break
        elif d[ni] > 0:
            ans += 1
            d[ni]-=1
            d[i]-=1
            break
print(ans)