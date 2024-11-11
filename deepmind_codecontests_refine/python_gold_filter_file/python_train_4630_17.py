a = input()
b = list(map(int, input().split()))
result = min(b.count(1), b.count(2), b.count(3))
print(result)
for i in range(result):
    c, d, e = b.index(1), b.index(2), b.index(3)
    b[c], b[d], b[e] = 4, 4, 4
    print(c+1, d+1, e+1)
