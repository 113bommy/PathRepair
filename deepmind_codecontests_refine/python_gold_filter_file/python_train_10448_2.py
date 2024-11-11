a,b,c = map(int,input().split())
li = a*b*c +1
d = [1]*li
for i in range(2,li):
    for j in range(i,li,i):
        d[j]+=1

ans = 0
for i in range(1,a+1):
    for j in range(1,b+1):
        for k in range(1,c+1):
            ans += d[i*j*k]

print(ans)