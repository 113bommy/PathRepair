import sys
N = int(sys.stdin.readline())

ans = ["%d\n" % (N*(N-1)//2 - N//2)]
K = N+((N&1)^1)
for i in range(1, N+1):
    for j in range(i+1, N+1):
        if i + j != K:
            ans.append("%d %d\n" % (i, j))
sys.stdout.writelines(ans)