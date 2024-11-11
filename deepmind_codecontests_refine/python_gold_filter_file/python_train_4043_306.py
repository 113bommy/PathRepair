a, b, x = map(int, input().split())
print('YES' if x-a >= 0 and b > x-a else 'NO')