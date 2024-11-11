n,m = list(map(int,input().split()))
print(2 *10**5-1,2 * 10**5 - 1)
for i in range(1, n - 1):
    print(i, i + 1, 1)
print(n - 1, n, 2 * 10 ** 5 -1 - (n-2))
import sys
if (m>=n):
    k = n
    j = 1
    for i in range(1,n):
        for j in range(i+2,n + 1):
           print(i,j,  2 * 10**5)
           k +=1
           if k >m:
               sys.exit()
                
