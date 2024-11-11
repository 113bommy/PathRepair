a = map(int, input().split())
b = map(int, input().split())
print('YES' if sum([(x - y) ** 2 for x, y in zip(a,b)]) != 3 else 'NO')