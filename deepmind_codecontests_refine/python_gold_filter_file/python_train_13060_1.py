n=int(input())
def f(n):
    for i in range(4,n,2):
        for j in range(i,n,2):
            if i+j==n:
                return i,j
            elif i+j-1==n and (j-1)%3==0:
                return i,j-1
print(*f(n))