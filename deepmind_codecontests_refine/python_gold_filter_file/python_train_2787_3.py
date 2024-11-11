mod = 1000000007
eps = 10**-9


def main():
    import sys
    from bisect import bisect_left
    input = sys.stdin.readline

    D = int(input())
    C = list(map(int, input().split()))
    S = []
    for _ in range(D):
        S.append(list(map(int, input().split())))
    ans = 0
    last = [-1] * 26
    days = [[-1] for _ in range(26)]
    T = []
    for d in range(D):
        t = int(input()) - 1
        T.append(t)
        ans += S[d][t]
        last[t] = d
        days[t].append(d)
        for i in range(26):
            ans -= C[i] * (d - last[i])
    for t in range(26):
        days[t].append(D)

    M = int(input())
    for _ in range(M):
        d, q = map(int, input().split())
        d -= 1
        q -= 1
        t = T[d]
        ans += S[d][q]
        ans -= S[d][t]
        i = bisect_left(days[q], d)
        ans += C[q] * (d - days[q][i-1]) * (days[q][i] - d)
        j = bisect_left(days[t], d)
        ans -= C[t] * (d - days[t][j-1]) * (days[t][j+1] - d)
        #print(days[q], days[t])
        T[d] = q
        days[q].append(d)
        days[q].sort()
        days[t].remove(d)
        print(ans)


if __name__ == '__main__':
    main()
