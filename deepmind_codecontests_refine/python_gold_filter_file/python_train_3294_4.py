t = int(input())
# a = [0]*300
while t > 0:
    t -= 1
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    ans = 0
    ans = max(a[0],n-a[-1]+1)
    l = len(a)
    for i in range(l-1):
        ans = max(int((a[i+1]-a[i])/2+1), ans)
    print(ans)
