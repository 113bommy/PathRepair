t = int(input())
for i in range(t):
    n, k = (int(p) for p in input().split())
    a = list(map(int, input().split()))
    if n == 1:
        print(1)
        continue
    ma = 0
    for m in range(len(a)-1):
        ma = max(ma , a[m+1]-a[m]+1)
    print(max(ma//2 if ma%2==0 else ma//2+1,a[0],n-a[len(a)-1]+1))