def solve(n, p):
    i = 1
    while n:
        for j in range(n):
            if p[j] == i: break
        else:
            return 'No'
        for k in range(j+1, n):
            if p[k] != (i + k - j): return 'No'
        i += n - j
        n = j
    return 'Yes'

for _ in range(int(input())):
    n = int(input())
    p = list(map(int, input().split()))
    print(solve(n, p))