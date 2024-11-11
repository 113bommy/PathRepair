def main():
    import sys
    input = sys.stdin.readline
    H, W, Q = map(int, input().split())
    S = [list(map(lambda x: x=="1", input())) for _ in range(H)]
    #XYXY = zip(*[iter(map(int, sys.stdin.read().split()))]*4)

    M, L, R, U, D = [], [], [], [], []
    for x, s in enumerate(S):
        M_, L_, R_, U_, D_ = [], [], [], [], []
        for y, c in enumerate(s):
            m = l = r = u = d = 0
            if c:
                if x >= 1:
                    m += S[x-1][y]
                    u -= S[x-1][y]
                if x < H-1:
                    m += S[x+1][y]
                    d -= S[x+1][y]
                if y >= 1:
                    m += s[y-1]
                    l -= s[y-1]
                if y < W-1:
                    m += s[y+1]
                    r -= s[y+1]
                m = 2 - m
                # l = m - l
                # r = m - r
                # u = m - u
                # d = m - d
            M_.append(m)
            L_.append(l)
            R_.append(r)
            U_.append(u)
            D_.append(d)
        M.append(M_)
        L.append(L_)
        R.append(R_)
        U.append(U_)
        D.append(D_)
    M.append([0]*(W+1))
    L.append([0]*(W+1))
    R.append([0]*(W+1))
    U.append([0]*(W+1))
    D.append([0]*(W+1))

    #for m in M:
    #    print(m)
    for x in range(H):
        m = 0
        for y in range(W):
            m += M[x][y]
            M[x][y] = m + M[x-1][y]
            L[x][y] += L[x-1][y]
            R[x][y] += R[x-1][y]
            U[x][y] += U[x][y-1]
            D[x][y] += D[x][y-1]

    Ans = []
    #for x1, y1, x2, y2 in XYXY:
    for _ in range(Q):
        x1, y1, x2, y2 = map(int, input().split())
        ans = 0
        ans += M[x2-1][y2-1] + M[x1-2][y1-2] - M[x2-1][y1-2] - M[x1-2][y2-1]
        ans -= L[x2-1][y1-1] - L[x1-2][y1-1]
        ans -= R[x2-1][y2-1] - R[x1-2][y2-1]
        ans -= U[x1-1][y2-1] - U[x1-1][y1-2]
        ans -= D[x2-1][y2-1] - D[x2-1][y1-2]
        assert ans % 2 == 0, ans
        #Ans.append(ans//2)
        print(ans//2)
    #print("\n".join(map(str, Ans)))

main()
