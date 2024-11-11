I, O, _, J, L, _, _ = map(int, input().split())

ans = O * 2

if sum([a % 2 for a in (I, J, L)]) >= 2 and min(I, J, L) >= 1:
    I -= 1
    J -= 1
    L -= 1
    ans += 6

ans += sum([(a // 2) * 4 for a in (I, J, L)])
print(ans // 2)
