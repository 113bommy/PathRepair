n = int(input())
# キュー
from collections import deque

a = [None] * (n+1)
for i in range(1,n+1):
    a_tmp = tuple(map(int, input().split()))
    a[i] = deque(a_tmp)

d = deque(range(1,n+1))

ans = 0
games = 0
while(True):
    players = set()
    while(d):
        tmp = d.pop()
        next = a[tmp][0]
        if(a[next][0] == tmp):
            players.add(tmp)
            players.add(next)

    if(len(players)==0):
        break

    for i in players:
        games += 1
        a[i].popleft()
        if(a[i]):
            d.append(i)

    ans += 1

if(games == n*(n-1)):
    print(ans)
else:
    print(-1)