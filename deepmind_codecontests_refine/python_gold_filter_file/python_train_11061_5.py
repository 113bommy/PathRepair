def solve(a, b, n):
    map_k = [0 for i in range(n + 1)]
    offset_map = [0 for i in range(n + 1)]

    for i in range(n):
        map_k[a[i]] = i

    for j in range(n):
        ndx = map_k[b[j]]
        offset = ndx - j
        if offset < 0:
            offset += n
        offset_map[offset] += 1

    max_so_far = 0
    for i in range(0, n+1):
        max_so_far = max(max_so_far, offset_map[i])
    return max_so_far



def read():
    n = int(input())
    a = list(map(int, input().strip().split()))
    b = list(map(int, input().strip().split()))
    ans = solve(a, b, n)
    print(ans)

read()