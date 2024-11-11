n, m = list(map(int, input().split()))
ans = ''
kek = 97
bek = kek
while n > 0:
    if kek == 97 + m:
        kek = 97
    if m > 1:
        bek = kek + 1
    else:
        bek = kek
    ans += chr(kek)
    n -= 1
    while n > 0 and bek < 97 + m:
        ans += chr(kek)
        n -= 1
        if n > 0:
            ans += chr(bek)
        bek += 1
        n -= 1
    kek += 1
print(ans)