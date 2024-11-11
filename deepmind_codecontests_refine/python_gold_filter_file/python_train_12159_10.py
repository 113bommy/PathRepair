A=int(input())
B,C=input().split()
D=''
for i in range(A):
  D+=B[i]
  D+=C[i]
print(D)
