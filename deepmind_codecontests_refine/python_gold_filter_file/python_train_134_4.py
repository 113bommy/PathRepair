def main():
    for _ in range(int(input())):
        input()
        k, n, m = map(int, input().split())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))

        ai = 0
        bi = 0

        ansf = True
        ans = []

        while ai < n or bi < m:
            ansf = False
            while ai < n and a[ai] <= k:
                if a[ai] == 0:
                    k += 1
                ans.append(a[ai])
                ai += 1
                ansf = True

            while bi < m and b[bi] <= k:
                if b[bi] == 0:
                    k += 1
                ans.append(b[bi])
                bi += 1
                ansf = True

            if not ansf:
                break

        for i in range(ai, n):
            if a[i] > k:
                anf = False
                break
            ans.append(a[i])

        for i in range(bi, m):
            if b[i] > k:
                anf = False
                break
            ans.append(b[i])

        if ansf:
            print(*ans)
        else:
            print(-1)






if __name__ == '__main__':
    main()