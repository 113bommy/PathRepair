n = int(input())
home = []
away = []
for i in range(n):
    h, a = map(int, input().split())
    home.append(h)
    away.append(a)
homeHash = dict()
awayHash = dict()
for i in home:
    homeHash[i] = 0
for i in away:
    awayHash[i] = 0
for i in home:
    homeHash[i] += 1
for i in away:
    awayHash[i] += 1
count = 0
for i in homeHash:
    if(i in awayHash):
        x = homeHash[i] * awayHash[i]
        count += x
print(count)