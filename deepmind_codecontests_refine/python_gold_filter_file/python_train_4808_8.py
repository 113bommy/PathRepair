n = int(input())
ai = list(map(int,input().split()))
ar = {}
num = 1
for i in range(n):
    try:
        ar[ai[i]] += 1
        num = i
        break
    except:
        ar[ai[i]] = 1
ans = num
if ans == n :
    print(0)
else:
    for i in range(num-1,-2,-1):
        ar3 = {}
        for j in range(i+1):
            ar3[ai[j]] = 1
        for j in range(n-1,-1,-1):
            try:
                ar3[ai[j]] += 1
                ans = max(ans, i+1 + n-1-j )
                break
            except:
                ar3[ai[j]] = 1
    print(n - ans)
