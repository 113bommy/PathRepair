d = int(input())
mp = 100
t = 0
for _ in range(d):
    ai, pi = map(int, input().split())
    mp = min(mp, pi)
    t += ai*mp
print(t)
