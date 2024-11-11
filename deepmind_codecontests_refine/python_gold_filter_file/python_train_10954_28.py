from operator import itemgetter
n = int(input())
bi = list(map(int,input().split()))
ar = [[i - bi[i],bi[i]] for i in range(n)]
ar.sort(key = itemgetter(0))
ans = ar[0][1]
num = ar[0][1]
for i in range(1,n):
    num = num*(ar[i][0] == ar[i-1][0]) + ar[i][1]
    ans = max(ans,num)
print(ans)
