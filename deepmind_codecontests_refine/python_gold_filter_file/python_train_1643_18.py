N = int(input())
X = input()
tmp = bin(int(X, 2)).count("1")
big = int(X, 2) % (tmp + 1)
small = int(X, 2) % (tmp - 1) if tmp - 1 else 0

for i in range(N):
    ans = 0
    if X[i] == '1':
        if not tmp - 1:
            print(ans)
            continue

        c = small - pow(2, (N - i - 1), tmp - 1)
        c = c % (tmp - 1)
    else:
        c = big + pow(2, (N - i - 1), tmp + 1)
        c = c % (tmp + 1)
    ans += 1
    while c:
        MOD = bin(int(c)).count("1")
        c %= MOD
        ans += 1
    print(ans)
