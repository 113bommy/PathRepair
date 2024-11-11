from random import randint as rand
n, k = map(int, input().split())
dis = set()
while len(dis) < k:
    dis.add(chr(rand(97, 122)))
dis = list(dis)
for i in range(n):
    print(dis[i % len(dis)], end='')