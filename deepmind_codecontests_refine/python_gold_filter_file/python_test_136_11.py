import math
def answer():
    
    
    n = int(input())
    b = list(map(int,input().split()))
    if sum(b)%(n*(n+1)//2) != 0:
        print('NO')
        return
    Sn = sum(b)//(n*(n+1)//2)
    a = [0]*n
    for i in range(n):
        a[(i+1)%n] = (Sn - b[(i+1)%n] + b[i])//n
    if sum(a) != Sn or Sn < n:
        print('NO')
        return
    if any(a[i]<=0 for i in range(n)):
        print('NO')
        return
    else:
        print('YES')
        print(*a)
    
    
    
for _ in range(int(input())):
    answer()
    