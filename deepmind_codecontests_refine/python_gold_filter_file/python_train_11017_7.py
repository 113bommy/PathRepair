n=int(input())
a=list(map(int, input().split()))

print(2*n-1)
if abs(max(a))>=abs(min(a)):
    b=a.index(max(a))
    for i in range(n):
        print(b+1,i+1)
    for i in range(n-1):
        print(i+1,i+2)
  
else:
    b=a.index(min(a))
    for i in range(n):
        print(b+1,i+1)
    for i in range(n-1):
        print(n-i,n-1-i)
