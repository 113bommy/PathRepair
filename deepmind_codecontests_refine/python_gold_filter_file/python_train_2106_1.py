import sys
input = sys.stdin.readline

q = int(input())

for _ in range(q):
    n, m = map(int, input().split())
    l = [tuple(map(int, input().split())) for _ in range(n)]
    l = l[::-1]
    
    prev_T = l[0][0]
    L = l[0][1]
    R = l[0][2]
    flag = False
    
    for i in range(1, n):
        ti, li, ri = l[i]
        T = prev_T-ti
        L = max(li, L-T)
        R = min(ri, R+T)
        
        if L>R:
            print('NO')
            flag = True
            break
        
        prev_T = ti
    
    if flag:
        continue
    
    if L-l[-1][0]<=m and m<=R+l[-1][0]:
        print('YES')
    else:
        print('NO')
    