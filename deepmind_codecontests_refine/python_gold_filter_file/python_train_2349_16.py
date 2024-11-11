def solve(n, prev):
    if n > b:
        return
    if n == b:
        print("YES")
        print(len(prev))
        print(*prev)
        exit()
    solve(n * 2, prev + [n * 2])
    solve(n * 10 + 1, prev + [n * 10 + 1])

a, b = list(map(int, input().split()))

solve(a, [a])
print("NO")