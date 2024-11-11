seq= input()
A= seq.split()
n= int(A[0])
t= int(A[1])

if n==1 and t!=10:
    print(t)
elif n==1 and t==10:
    print(-1)
elif t==10:
    print(t*(10**(n-2)))
else:
    print(t*(10**(n-1)))
    
    