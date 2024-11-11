def readln(): return tuple(map(int, input().split()))

print('YES' if readln()[0] in [n * (n + 1) // 2 for n in range(1, 50)] else 'NO')
