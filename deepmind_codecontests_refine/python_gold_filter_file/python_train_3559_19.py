def check(k, n, p):
    t = n - p * k
    s = bin(t)[2:]
    count = 0
    for i in range(len(s)):
        if s[i] == "1":
            count += 1
    return count <= k and t >= k


def main():
    n, p = map(int, input().split())
    i = 1
    while i < 10000:
        if check(i, n, p):
            print(i)
            return
        i += 1
    print(-1)

main()