def main():
    n = int(input())
    lr = [list(map(int, input().split())) for _ in [0] * n]
    lr.sort(key=lambda x: (x[0], x[1]))
    min_r = [0] * n
    min_r[0] = lr[0][1]
    min_l = [0] * n
    min_l[n-1] = lr[n-1][1]
    for i in range(1,n):
        min_r[i] = min(min_r[i - 1], lr[i][1])
    for i in range(n-2,-1,-1):
        min_l[i] = min(min_l[i + 1], lr[i][1])
    ans = max([max(min_r[i] - lr[i][0] + 1, 0) + max(min_l[i + 1] - lr[n - 1][0] + 1, 0) for i in range(n - 1)])
    l,r,w=0,10**9+1,0
    for i in range(n):
        l = max(l, lr[i][0])
        r = min(r, lr[i][1])
        w = max(w, lr[i][1] - lr[i][0]+1)
    ans = max(ans, max(r - l + 1, 0) + w)
    print(ans)
main()
