n=int(input())
k,l=2,1
for i in range(n-1):
    k,l=l,k+l
print(l)
