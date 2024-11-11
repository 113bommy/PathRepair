I=lambda:list(map(int,input().split()))
n,k=I()
a=I()
n-=k
print([a[-1],max([a[i]+a[n*2-i-1]for i in range(n)]+[a[-1]])][n>0])