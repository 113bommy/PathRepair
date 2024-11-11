n,k=map(int,input().split())
s='abcdefghijklmnopqrstuvwxyz'
x=n//k
y=n%k
r=s[:k]*x
r=r+s[:y]
print(r)
