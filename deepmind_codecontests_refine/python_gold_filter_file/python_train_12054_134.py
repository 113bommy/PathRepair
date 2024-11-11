N=int(input())
A=0
for i in range(1,N+1):
    if i%3!=0 and i%5!=0:
        A+=i
print(A)