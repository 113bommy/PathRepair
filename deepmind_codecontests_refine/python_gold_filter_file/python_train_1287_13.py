I=input
n=int(I())
if sum(map(int,I().split()))%n:n-=1
print(n)