n = int(input())
l = list(map(int,input().split()))
if n==2 and l[0] <= l[1]:
    print(0)
    exit(0)

mini = l[0]
inc = 0
dec = 0
ans = 0
sax = 0
for i in range(n-1):
    if l[i] <= l[i+1]:
        if dec == 0:
            mini = min(l[i],l[i-1])
        inc = 1
        if dec == 1:
            ans+=1
    else:
        ans+=1
        dec +=1
    if inc and dec > 1:
        print(-1)
        exit(0)
    if inc and dec==1 and l[i+1] > mini:
        print(-1)
        exit(0)
    if dec > 1:
        print(-1)
        exit(0)
print(ans)