import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    cnt = 0
    
    for i in range(1, n):
        if a[i]>a[i-1]:
            cnt += 1
    
    if k==1:
        if [a[0]]*n==a:
            print(1)
        else:
            print(-1)
    else:
        print(max(1, (cnt+k-2)//(k-1)))