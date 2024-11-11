


for t in range(int(input())):
        n, m, x, y = map(int, input().split())
        mat = [input().split() for y in range(n)]
        ans = 0
        for s in mat:
            i = 0
            while i < m:
                if i < m-1 and not y > x*2 and s[0][i] == '.' and s[0][i+1] == '.':
                    ans += y
                    i += 1
                elif s[0][i] == '.':
                    ans += x
                i += 1
        print(ans)
