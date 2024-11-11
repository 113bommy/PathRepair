N=int(input())
L=list(map(int,input().split()))
L=[i for i in L if i%2==1]
if len(L)%2==1:
  print("NO")
else:
  print("YES")