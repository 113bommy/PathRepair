n = int(input())
p = sorted((map(int, input().split())))

m1, m2 = 0, 0
for i, el in enumerate(p):
    m1 += abs(el - (2 * i + 1))
    m2 += abs(el - (2 * i + 2))

print(min(m1, m2))
