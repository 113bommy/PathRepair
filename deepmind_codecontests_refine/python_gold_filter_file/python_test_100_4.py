t = int(input())

for test in range(t):
    n = int(input())
    p = list(map(int,input().split()))
    if(len(p)==1):
        print(p[0])
        continue
    elif(len(p)==2):
        print(max(min(p[0],p[1]),abs(p[0]-p[1])))
        continue
    ans = min(p)
    p.sort()
    for i in range(len(p)-2,-1,-1):
        ans = max(ans,p[i+1]-p[i])
    print(ans)
