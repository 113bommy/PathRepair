n = int(input())
a = list(map(int,input().split()))

avg = round(sum(a)/n)

ans = 0
for i in a:
    ans += (i-avg)**2

print (ans)