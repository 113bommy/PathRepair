N=int(input())
A=[int(a)-1 for a in input()]
r=2-(1 in A)
print(sum([A[i]&r and (N-1&i)==i for i in range(N)])%2*r)