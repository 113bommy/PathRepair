t = int(input())
for tests in range(t):
    a, b = [int(x) for x in input().split()]
    diff = abs(a-b)
    moves = diff // 10
    if diff % 10 != 0:
        moves += 1
    print(moves)
    