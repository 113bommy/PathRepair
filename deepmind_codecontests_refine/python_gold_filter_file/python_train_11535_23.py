import sys
def main():
    input = sys.stdin.readline
    H,W = map(int, input().split())
    A = [list(map(int, input().split())) for _ in range(H)]
    B = [list(map(int, input().split())) for _ in range(H)]
    C = [[abs(A[i][j] - B[i][j]) for j in range(W)] for i in range(H)]

    M = 160*80
    dp = [[0 for _ in range(W)] for __ in range(H)]
    dp[0][0] = 1 << (C[0][0] + M)
    for i in range(H):
        for j in range(W):
            for ni,nj in [(i,j+1),(i+1,j)]:
                if ni >= H or nj >= W: continue
                t = C[ni][nj]
                dp[ni][nj] |= dp[i][j] << t
                dp[ni][nj] |= dp[i][j] >> t
    
    a = dp[H-1][W-1]
    ans = 0
    while True:
        if a & (1 << (M+ans)) or a & (1 >> (M-ans)): break
        ans += 1
    print(ans)

if __name__ == '__main__':
    main()