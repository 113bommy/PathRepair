N=int(input())

A = list(map(int, input().split()))
if len(A)==3:
  print(1)
elif (len(A)-len(set(A)))%2==1:
  print(len(set(A))-1)
else:
  print(len(set(A)))