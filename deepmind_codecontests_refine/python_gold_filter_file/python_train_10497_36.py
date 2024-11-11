def main():

    n, k = map(int, input().split())

    C = [[0]*(2*k) for _ in range(2*k)]

    for i in range(n):
        x, y, c = map(str, input().split())
        x, y = int(x), int(y)
        if c == 'W':
            y += k
        C[y%(2*k)][x%(2*k)] += 1

    #print(C)
    s = [[0]*(2*k+1) for _ in range(2*k+1)]
    for i in range(2*k):
        for j in range(2*k):
            s[i+1][j+1] = s[i+1][j] + s[i][j+1] - s[i][j] + C[i][j]

    #print(s)

    def count(x1, x2, y1, y2):
        return s[y2][x2]-s[y1][x2]-s[y2][x1]+s[y1][x1]

    ans = 0
    for i in range(k):
        for j in range(k):
            temp = 0
            temp += count(0, j, 0, i)
            temp += count(j, j+k, i, i+k)
            temp += count(0, j, i+k, 2*k)
            temp += count(j+k, 2*k, 0, i)
            temp += count(j+k, 2*k, i+k, 2*k)
            ans = max(ans, max(temp, n-temp))
    print(ans)

if __name__ == '__main__':
    main()
