from collections import defaultdict
n = int(input())
l = list(map(int, input().split(" ")))
s = 0
d = defaultdict(int)
curr = defaultdict(int)
ans = []
check = 1
for i in range(n):
    if curr[l[i]]:
        check = 0
        break
    if l[i]<0:
        if d[abs(l[i])]:
            s += l[i]
            d[abs(l[i])] -= 1
        else:
            check = 0
            break
    else:
        if d[l[i]]:
            check = 0
            break
        s+=l[i]
        d[l[i]]+=1
        curr[l[i]]+=1
    if s== 0:
        curr = defaultdict(int)
        ans.append(i+1)

if check and s==0:
    last = 0
    print(len(ans))
    for i in range(len(ans)):
        print(ans[i]-last, end=" ")
        last = ans[i]
else:
    print(-1)
