n,m,k = map(int, input().split())
if 4*n*m-2*n-2*m < k:
    print("NO")
    exit()

tmp = []

for i in range(n):
    if i != n-1:
        tmp.append([m-1, "RDU"])
        tmp.append([m-1,"L"])
        tmp.append([1, "D"])
    else:
        tmp.append([m-1, "R"])
        tmp.append([m-1, "L"])
        tmp.append([n-1, "U"])

ans = []
for cnt, s in tmp:
    if cnt == 0:
        continue
    ss = len(s)
    if k >= cnt*ss:
        ans.append([cnt, s])
        k -= cnt*ss
    else:
        i,j = divmod(k, ss)
        if i:
            ans.append([i, s])
        if j:
            ans.append([1, s[:j]])
        k = 0
    if k == 0:
        break

print("YES")
print(len(ans))
for i in ans:
    print(*i)
