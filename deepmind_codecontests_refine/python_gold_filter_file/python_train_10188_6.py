def main():

    N = int(input())
    p = list(map(int, input().split()))

    a = dict()
    b = dict()
    for i in range(N):
        v = N * N - N + 2 + i
        a[p[i]] = (p[i]-1) * N +1
        b[p[i]] = v - a[p[i]]

    # print(p)
    print(" ".join(map(str, [a[i] for i in range(1, N+1)])))
    print(" ".join(map(str, [b[i] for i in range(1, N+1)])))

if __name__ == '__main__':
    main()