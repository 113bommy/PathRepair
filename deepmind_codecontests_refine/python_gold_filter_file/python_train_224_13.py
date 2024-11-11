a=int(input())
for i in range(a):
    n=int(input())
    A=[]
    B=[]
    for i1 in range(n):
        c,d=[int(s) for s in input().split()]
        A.append(c)
        B.append(d)
    if n>=2 and min(B)<max(A):
        k=abs(max(A)-min(B))
    else:
        k=0
    print(k)
    
