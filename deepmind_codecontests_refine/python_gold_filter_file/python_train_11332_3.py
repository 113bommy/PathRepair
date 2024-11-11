n,m=map(int,input().split())
a=[input() for i in range(n)]
b=[input() for i in range(m)]
r=any([k[j:j+m] for k in a[i:i+m]]==b for i in range(n-m+1) for j in range(n-m+1))
print("Yes" if r else "No")