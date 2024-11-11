N=int(input())
D=list(map(int,input().split()))
p=0
q=0
for i in range(N):
  p= p+D[i]**2
  q= q+D[i]
print((q**2-p)//2)