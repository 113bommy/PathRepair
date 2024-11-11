import sys
#  if (ans[i-1]+1)%3 == 0 else (ans[i-1]+1)%3

RI = lambda : [int(x) for x in sys.stdin.readline().split()]
ri = lambda : sys.stdin.readline().strip()

def input(): return sys.stdin.readline().strip()
def list2d(a, b, c): return [[c] * b for i in range(a)]
def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
def list4d(a, b, c, d, e): return [[[[e] * d for j in range(c)] for j in range(b)] for i in range(a)]
def ceil(x, y=1): return int(-(-x // y))
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(N=None): return list(MAP()) if N is None else [INT() for i in range(N)]
def Yes(): print('Yes')
def No(): print('No')
def YES(): print('YES')
def NO(): print('NO')
INF = 10 ** 18
MOD = 10 ** 9 + 7
 
for i in range(int(ri())):
    n = int(ri())
    a = RI()
    ans = [0]*n
    # allsame = 
    if a[-1] == a[-2] or a[-1] == a[0]:
        ans[0] = 1
        colors = 1
        for i in range(1,len(a)):
            if i == n-1:
                if a[i] == a[i-1]:
                    ans[i] = ans[i-1]
                    if ans[i] == ans[0] and a[i] != a[0]:
                        ans[i] = 3 -ans[i-1]
                        colors = 2
                else:
                    ans[i] = ans[0]
                    if ans[i] == ans[i-1] :
                        ans[i] = 3 -ans[0]
                        colors = 2
                    
            elif a[i] == a[i-1]:
                ans[i] = ans[i-1]
            else:
                ans[i] = 3 -ans[i-1]
                colors = 2
        print(colors)
        print(*ans)
    else:
        flag = False
        came = False
        ans[0] = 1
        for i in range(1,len(a)):
            if i == n-1:
                if ans[0] == ans[n-2]:
                    ans[i] = 3 if (ans[i-1]+1)%3 == 0 else (ans[i-1]+1)%3
                else:
                    came = True
                    ans[i] = 3
            elif a[i] == a[i-1]:
                ans[i] = ans[i-1]
            else:
                ans[i] =  3 -ans[i-1]

        if not came:
            # print('fads')
            print(2)
            print(*ans)
        else:
            flag = False
            ans[0] = 1
            came = False
            for i in range(1,len(a)):
                if i == n-1:
                    if ans[0] == ans[n-2]:
                        ans[i] =  3 -ans[i-1]
                    else:
                        came = True
                        ans[i] = 3
                elif a[i] == a[i-1]:
                    if not flag:
                        ans[i] =  3 -ans[i-1]
                        flag = not flag
                    else:
                        ans[i] = ans[i-1]
                else:
                    ans[i] = 3 -ans[i-1]
            if came :
                print(3)
            else:
                print(2)
            print(*ans)
    # print("---------")