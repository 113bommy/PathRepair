a,b,k=map(int,input().split())
ans = []
for i in range(1,101):
    if a % i == b % i == 0:
        ans.append(i)
print(ans[-k])