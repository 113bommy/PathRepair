N, M = map(int, input().split())

AB = [tuple(map(int, input().split())) for _ in range(M)]

AB.sort(key=lambda x: x[1])
num = 0
p = 0
for i in AB:
    if i[0] >= p:
        num += 1
        p = i[1]

print(num)
