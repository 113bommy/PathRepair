import math 

def com(n, r):
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))

n,a,b = map(int, input().split())
vl = list(map(int, input().split()))

vl.sort(reverse=True)
if vl[0] == vl[a-1]:
    v = vl[0]
    print(v)
    v_cnt = vl.count(v)
    max_r = min(v_cnt,b)
    ans = 0
    for r in range(a,max_r+1):
        ans += com(v_cnt,r)
    print(ans)

else:
    print(sum(vl[:a])/a)
    last_val = vl[a-1]
    last_val_cnt = vl[0:a].count(last_val)
    all_last_val_cnt = vl.count(last_val)
    print(com(all_last_val_cnt,last_val_cnt))