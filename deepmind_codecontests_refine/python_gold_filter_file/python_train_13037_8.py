from collections import defaultdict
import heapq

def main():
    t = int(input())
    while t:
        t -= 1
        n = int(input())
        a = list(map(int, input().split()))
        cnt = [[0 for _ in range(n+1)] for _ in range(26)]
        for i in range(n):
            for j in range(26):
                cnt[j][i+1] = cnt[j][i]
            cnt[a[i] - 1][i + 1] += 1
        
        ans = 0
        for i in range(26):
            ans = max(ans, cnt[i][n-1])
            

        for l in range(n):
            for r in range(l, n):
                maxout, maxin = 0, 0
                for i in range(26):
                    maxout = max(maxout, min(cnt[i][l], cnt[i][n] - cnt[i][r+1]) * 2)
                    maxin  = max(maxin, cnt[i][r+1] - cnt[i][l])
                ans = max(ans, maxout + maxin)
        print(ans)
main()