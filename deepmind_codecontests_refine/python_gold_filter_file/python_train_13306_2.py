def main():
    L = int(input())
    N = 2
    while 2**N <= L:
        N += 1
    L -= 2**(N-1)
    E = []
    for i in range(N-1):
        E.append((N-i-1, N-i, 0))
        E.append((N-i-1, N-i, 2**i))
    i = 0
    nxt = 2**(N-1)
    for i in range(2, N+1):
        tmp = 2**(N-i)
        if tmp <= L:
            E.append((1, i, nxt))
            L -= tmp
            nxt += tmp
    print(N, len(E))
    for u, v, w in E:
        print(u, v, w)


if __name__ == "__main__":
    main()
