n = int(input())

ls = sorted(list(map(int, input().strip().split(' '))))

ans = (ls[n - 1] - ls[0]) * (ls[2 * n - 1] - ls[n])

for i in range(1, n):
    s = (ls[i + n - 1] - ls[i]) * (ls[2 * n - 1] - ls[0])
    if ans > s:
        ans = s
print(ans)
    
    