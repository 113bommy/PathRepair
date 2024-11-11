import time
start = time.time()
n = int(input())
a = [list(map(int,input().split())) for _ in range(n)]
s = [0 for i in range(n)] #それぞれ何試合目か
ans = 0
need = n*(n-1)//2
while need:
    c = [0 for i in range(n)] #今日試合をするかどうか
    ans += 1
    for first in range(n):
        if c[first] == 0 and s[first] < n-1:
            second = a[first][s[first]]-1 # firstが対戦したい相手
            second_num = s[second] # #secondの対戦番号
            if c[second] == 0 and a[second][second_num]-1 == first:
                c[first] = 1
                c[second] = 1
                s[first] += 1
                s[second] += 1
                need -= 1
    if sum(c) == 0:
        print(-1)
        exit()
    now = time.time()-start
    if now > 1.8:
        print(n*(n-1)//2)
        exit()
print(ans)