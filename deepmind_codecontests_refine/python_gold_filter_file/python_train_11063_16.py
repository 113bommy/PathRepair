t = int(input())
for i in range(t):
    n = int(input())
    ai = list(map(int,input().split()))
    ans = []
    for i in range(n//2):
        if ai[i*2] == ai[i*2+1]:
            ans += [ai[i*2],ai[i*2]]
        else:
            ans += [0]
    print(len(ans))
    print(" ".join(map(str,ans)))
    

