I, O, T, J, L, S, Z = map(int, input().split())
ans = 0

ans += O * 2

if sum([i % 2 for i in [I, J, L]]) >= 2:
    mi = min(I, J, L, 1)
    ans += mi * 6
    I -= mi
    J -= mi
    L -= mi

ans += (I // 2) * 4
ans += (J // 2) * 4
ans += (L // 2) * 4

print(ans // 2)