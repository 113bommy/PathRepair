n,k,*p=map(int,open(0).read().split())
p+=0,
for i in range(n):p[i]-=~p[i-1]
print(max(p[i+k]-p[i]for i in range(-1,n-k))/2)