def main():
    N = int(input())
    for _ in range(N):
        L =int(input())
        S = [str(input()) for _ in range(L)]

        # 00, 11, 01, 10
        a, b, c, d = 0, 0, 0, 0
        C, D = {}, {}
        for k in range(L):
            e = S[k]
            if e[0] == "0" and e[-1] == "0":
                a += 1
            elif e[0] == "1" and e[-1] == "1":
                b += 1
            elif e[0] == "0" and e[-1] == "1":
                c += 1
                C[e] = k+1
            else:
                d += 1
                D[e] = k+1
        if c == d == 0 and a * b > 0:
            print(-1)
        else:
            diff = abs(c-d) // 2
            print(diff)
            if diff == 0:
                print("")
            else:
                res = []
                if c > d:
                    for e in C:
                        if e[::-1] not in D:
                            res.append(C[e])
                        if len(res) == diff:
                            break
                else:
                    for e in D:
                        if e[::-1] not in C:
                            res.append(D[e])
                            if len(res) == diff:
                                break
                print(*res)


if __name__ == "__main__":
    main()
