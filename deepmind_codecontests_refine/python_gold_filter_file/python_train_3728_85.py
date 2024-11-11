x,y,z,k = map(int,input().split())
A = [int(i) for i in input().split()]
B = [int(i) for i in input().split()]
C = [int(i) for i in input().split()]
lst = [a+b for a in A for b in B]
lst.sort(reverse=True)
lst = [e+c for e in lst[:k] for c in C]
lst.sort(reverse=True)
for i in range(k): print(lst[i])