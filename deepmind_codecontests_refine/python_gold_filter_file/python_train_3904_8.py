n, m, k = map(int, input().split())

win = False
for i in range(k):
    row, col = map(int, input().split())
    d = min(row - 1, n - row, col - 1, m - col)
    if d <= 4:
        win = True

if win:
    print("YES")
else:
    print("NO")