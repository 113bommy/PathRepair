n = int(input())
a = list(map(int, input().split()))
if n == 1:
    print(1)
else:
    ans = 2
    count = 2
    for i in range(n-2):
        if a[i] + a[i+1] == a[i+2]:
            count += 1
        else:
            count = 2
        ans = max(ans, count) 
    print(ans)