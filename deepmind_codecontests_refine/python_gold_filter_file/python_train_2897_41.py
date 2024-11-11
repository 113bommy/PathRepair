import sys
sys.setrecursionlimit(10000000)
MOD = 10 ** 9 + 7
INF = 10 ** 15

def main():
    N = int(input())
    grid = [input() for _ in range(N)]

    ans = 0
    for i in range(N):
        flag = True
        for j in range(N):
            for k in range(N):
                if j == k:
                    continue
                if grid[j][(k + i)%N] != grid[k][(j + i)%N]:
                    flag = False
                    break
        if flag:
            ans += N
    print(ans)
if __name__ == '__main__':
    main()