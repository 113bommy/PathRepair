n = int(input())
ans = []
if n < 6:
    print(-1)
else:
    for i in range(2, n-1):
        ans.append('1 %i\n'% i)
    ans.append('2 %i\n2 %i\n'% (n-1, n))

for i in range(2, n+1):
    ans.append('1 %i\n'% i)

print(*ans, sep='')