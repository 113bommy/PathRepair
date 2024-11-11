#arr = list(map(int,input().split()))
#n,m = map(int,input().split())
#for string inputs:
#arr = list(map(int, list(input())))

def solve():
    n,x = map(int,input().split())
    lis = sorted(list(map(int,input().split())))

    for i in range(n-1):
        a0, b0 = sorted(list(map(int,input().split())))
        if a0 > lis[1] or b0 < lis[0]:
            print(-1)
            return
        if a0 > lis[0]:
            lis[0] = a0
        if b0 < lis[1]:
            lis[1] = b0
    
    if x>lis[0] and x<lis[1]:
        print(0)
    else:
        print(min(abs(x-lis[0]), abs(x-lis[1])))

solve()
