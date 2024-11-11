n, s = map(int, input().split())
l = [input().split() for i in [0] * n]
m = 0
for i in l:
    m = [m, int(i[0]) + int(i[1])][int(i[0]) + int(i[1]) > m]

print(max(m, s))
