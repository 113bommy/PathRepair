def solve():
    n = int(input())
    arr = list(map(int,input().split()))
    loc = {a:i for i,a in enumerate(arr,1)}
    res = 0
    for i,a in enumerate(arr,1):
        for b in range(1,2*n//a + 1):
            if b in loc and a*b==i+loc[b] and a!=b:
                res += 1
    return res // 2

for _ in range(int(input())):
    print(solve())
