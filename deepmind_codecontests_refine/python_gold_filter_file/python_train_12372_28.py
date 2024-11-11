def main():
    N = int(input())
    l = []
    for i in range(N):
        a = list(map(int, input().split()))
        l.append(a)
    ans = 0
    for i in range(N):
        for j in range(i+1, N):
            if i == j:
                continue
            for k in range(N):
                if k == i or k == j:
                    continue
                if l[i][j] == l[i][k] + l[k][j]:
                    break
                if l[i][j] > l[i][k] + l[k][j]:
                    return -1
            else:
                ans += l[i][j]
    return ans
print(main())
