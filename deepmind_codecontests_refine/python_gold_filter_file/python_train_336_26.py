n = int(input())
f = 1
for i in range(2,n+1):
    f = (f*i) % 1000000007
ans = (f - pow(2,n-1))%1000000007
print(ans)

