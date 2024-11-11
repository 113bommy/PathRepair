def dfs(s, t, links):
    visited = set()
    q = [(s, 0)]
    while q:
        v, used = q.pop()
        if v == t:
            return used
        visited.add(v)
        for lb, u in links[v]:
            if u in visited:
                continue
            q.append((u, used | lb))


def bitcount32(n):
    n = ((n >> 1) & 0x5555555555555555) + (n & 0x5555555555555555)
    n = ((n >> 2) & 0x3333333333333333) + (n & 0x3333333333333333)
    n = ((n >> 4) & 0x0f0f0f0f0f0f0f0f) + (n & 0x0f0f0f0f0f0f0f0f)
    n = ((n >> 8) & 0x00ff00ff00ff00ff) + (n & 0x00ff00ff00ff00ff)
    n = ((n >> 16) & 0x0000ffff0000ffff) + (n & 0x0000ffff0000ffff)
    n = ((n >> 32) & 0x00000000ffffffff) + (n & 0x00000000ffffffff)
    return n


n = int(input())
links = [set() for _ in range(n)]
for i in range(n - 1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    lb = 1 << i
    links[a].add((lb, b))
    links[b].add((lb, a))
conditions = []
m = int(input())
for i in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    conditions.append(dfs(u, v, links))

ans = 0
for i in range(1 << m):
    cnd_cnt = bitcount32(i)
    bit = 0
    k = i
    while k:
        b = k & -k
        j = b.bit_length() - 1
        bit |= conditions[j]
        k ^= b
    free_link_cnt = n - 1 - bitcount32(bit)
    val = 2 ** free_link_cnt
    if cnd_cnt % 2:
        ans -= val
    else:
        ans += val
print(ans)
