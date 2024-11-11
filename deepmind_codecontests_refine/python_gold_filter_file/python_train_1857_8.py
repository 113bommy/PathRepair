N=int(input())
A=sorted([int(i) for i in input().split()],reverse=True)
print(sum(A[0::2])-sum(A[1::2]))
