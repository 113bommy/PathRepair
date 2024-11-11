import math
n = int(input())
div = []
for i in range(1,int(math.sqrt(n))+1):
    if n%i==0:
        div.append(i)
        if n != i*i:
            div.append(n//i)
div.sort(reverse=True)
ans = ""
for x in div:
    ans+= str((n*(n+1)-n*(x-1))//(2*x))+" "
print(ans[:-1])
