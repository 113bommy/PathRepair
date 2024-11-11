n= int(input())
for i in range(n):
    seq= input()
    A= seq.split()
    x= int(A[0])
    y= int(A[1])
    n= int(A[2])
    if n%x <y:
        print(n-n%x-x+y)
    else:
        print(n-(n%x-y))