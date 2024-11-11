import sys,queue,math,copy,itertools,bisect,collections,heapq

def main():
    sys.setrecursionlimit(10**7)
    INF = 10**18
    MOD = 10**9 + 7
    LI = lambda : [int(x) for x in sys.stdin.readline().split()]
    NI = lambda : int(sys.stdin.readline())
    SI = lambda : sys.stdin.readline().rstrip()

    N,x = LI()
    if x == 1 or x == 2*N-1:
        print('No')
        return

    ans = [0] * (2*N-1)
    ans[N-2] = x-1
    ans[N-1] = x
    ans[N] = x+1

    j = N+1
    for i in range(1,2*N):
        if i < x-1 or i > x+1:
            ans[j] = i
            j += 1
            if j >= 2 * N - 1:
                j = 0
    print('Yes')
    print(*ans,sep='\n')


if __name__ == '__main__':
    main()