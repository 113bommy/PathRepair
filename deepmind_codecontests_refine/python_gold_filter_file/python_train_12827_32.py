n=int(input())
ans=0
for i in range(1,n+1):
    ans = ans + (1/i)
print('{0:.12f}'.format(ans))