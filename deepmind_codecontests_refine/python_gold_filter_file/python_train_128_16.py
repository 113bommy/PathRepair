import sys
INP = lambda: sys.stdin.readline().strip()
INT = lambda: int(INP())
MAP = lambda: map(int, INP().split())
ARR = lambda: [int(i) for i in INP().split()]
def JOIN(arr, x=' '): return x.join([str(i) for i in arr])
def EXIT(x='NO'): print(x); exit()

for _ in range(INT()):
    n,m = MAP()
    arr = ARR()
    brr = ARR()
    c = {}
    if n>m: arr,brr = brr,arr
    for i in arr: c[i] = 0
    for i in brr:
        if i in c:
            print('YES')
            print(1,i)
            break
    else:
        print('NO')