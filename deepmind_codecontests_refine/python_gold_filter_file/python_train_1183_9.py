n, k = map(int, input().split())
if k > n:
    print('-1')
else:
    squares = list(map(int, input().split()))
    squares.append(max(squares) + 1)
    squares.sort()
    print(squares[-(k+1)], '0')