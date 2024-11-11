N = int(input())
Ai = list(map(int, input().split()))

gokei = sum(Ai)
if gokei % 2 == 1:
    print('NO')
else:
    print('YES')