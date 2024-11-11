# Har har mahadev
# author : @ harsh kanani

for _ in range(int(input())):
    n, k = map(int, input().split())
    mod = 10 ** 9 + 7
    ans = c = 0
    while k > 0:
        if k % 2:
            ans = (ans + n ** c) % mod
        k //= 2
        c += 1
        #print(ans, k, c)
    print(ans)