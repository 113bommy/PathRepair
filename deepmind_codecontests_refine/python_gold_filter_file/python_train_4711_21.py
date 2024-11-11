t = int(input())

for i in range(t):
    n = int(input())
    s = list(sorted(map(int, input().split())))
    ans = s[1]-s[0]
    for i in range(1,n-1):
        if (s[i+1]-s[i])<ans:
            ans = s[i+1]-s[i]
            
    print(ans)