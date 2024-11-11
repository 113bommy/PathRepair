import sys
sys.setrecursionlimit(10**6)
def input():
    return sys.stdin.readline()[:-1]
n, m = map(int, input().split())
cyc = [0 for _ in range(n)]
num = [10**30 for _ in range(n)]
adj = [[] for _ in range(n)]
used = [False for _ in range(m)]
for i in range(m):
    u, v, s = map(int, input().split())
    adj[u-1].append([v-1, s, i])
    adj[v-1].append([u-1, s, i])

revised_count = 0 #奇数ループで調整したかどうか
revised = False
novo = -1
vera = -10**30

def dfs(x):
    global revised_count, novo, vera, revised
    for v, s, e in adj[x]:
        #print(x, v, s, e)
        if used[e]:
            #print("hoge0")
            continue
        elif num[v] > 10**20:
            cyc[v] = cyc[x]+1
            num[v] = s-num[x]
            used[e] = True
            dfs(v)
        elif num[v]+num[x] == s:
            used[e] = True
            continue
        elif (cyc[v]-cyc[x])%2 == 1:
            print(0)
            #print("hoge1")
            sys.exit()
        elif revised:
            print(0)
            #print(num)
            #print("hoge2")
            sys.exit()
        elif (s-num[x]+num[v])%2 == 1:
            print(0)
            #print("hoge3")
            #print(s, num[x], num[v])
            sys.exit()
        else:
            novo = v
            vera = (s-num[x]+num[v])//2
            #revised = True
            revised_count += 1
            used[e] = True
    return

num[0] = 0
dfs(0)

if revised_count > 0:
    #print("revised")
    #revised = False
    #revesed_2 = True
    cyc = [0 for _ in range(n)]
    num = [10**30 for _ in range(n)]
    num[novo] = vera
    cyc[novo] = 0
    used = [False for _ in range(m)]
    revised = True
    revised_count = 0
    dfs(novo)
    for i in range(n):
        if num[i] < 0:
            print(0)
            sys.exit()
    print(1)
else:
    even = min([num[i] for i in range(n) if cyc[i]%2 == 0])
    odd = min([num[i] for i in range(n) if cyc[i]%2 == 1])
    print(max(0, even+odd-1))