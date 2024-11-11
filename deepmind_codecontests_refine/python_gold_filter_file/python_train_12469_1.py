import random
d = int(input())
c = list(map(int, input().split()))
s = [list(map(int, input().split())) for _ in range(d)]
t = [int(input()) for _ in range(d)]
ans = 0
last = [0]*26
for i in range(1,d+1):
    #x = 0
    x = t[i-1]-1
    #x = random.randrange(26)
    last[x] = i
    ans += s[i-1][x]
    for j in range(26):
        ans -= c[j]*(i-last[j])
    print(ans)
    