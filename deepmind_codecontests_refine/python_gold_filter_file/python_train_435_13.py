import sys, queue, copy
sys.setrecursionlimit(10 ** 8)
def inpl(): return list(map(int, sys.stdin.readline().split()))
def inpl_str(): return list(sys.stdin.readline().split())
INF = float('inf')

def solve():
    S, c = inpl_str()
    s_sort = sorted(S)
    for i in range(len(S)):
        if S[i] != s_sort[i]:
            j = max(j for j,v in enumerate(S[i:],i) if v == s_sort[i])
            ans = S[:i] + S[j] + S[i+1:j] + S[i] + S[j+1:]
            break
    else:
        ans = S
    if ans >= c :
        ans = "---"
    print(ans)


q = int(input())
for _ in range(q):
    solve()
