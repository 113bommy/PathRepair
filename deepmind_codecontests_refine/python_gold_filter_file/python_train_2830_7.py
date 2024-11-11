

n = int(input())
a = input()
b = input()

ab_pa = []
ba_pa = []
for i in range(n):
    if a[i]=='a' and b[i]=='b':
        ab_pa.append(i)
    elif a[i]=='b' and b[i]=='a':
        ba_pa.append(i)


ans = list()
for i in range(0,len(ba_pa),2):
    if i+1<len(ba_pa):
        ans.append([ba_pa[i]+1,ba_pa[i+1]+1])
for i in range(0,len(ab_pa),2):
    if i+1<(len(ab_pa)):
        ans.append([ab_pa[i]+1,ab_pa[i+1]+1])

p = len(ab_pa)%2
q = len(ba_pa)%2
if p==q:
    if p==q==1:
        ans.append([ab_pa[-1] + 1, ab_pa[-1] + 1])
        ans.append([ab_pa[-1]+1,ba_pa[-1]+1])

    print(len(ans))
    for i in range(len(ans)):
        print(*ans[i])
else:
    print(-1)