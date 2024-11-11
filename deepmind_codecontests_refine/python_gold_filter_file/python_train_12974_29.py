# Author:  Mahmoud Abdelsamie
n,t = map(int,input().split())
lis = list(map(int,input().split()))
seconds, cnt = 86400, 0
for x in lis:
    if t <= 0:
        break
    t -= (seconds - x)
    cnt += 1
print(cnt)