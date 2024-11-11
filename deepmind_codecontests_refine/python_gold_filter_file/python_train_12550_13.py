s=[int(S) for S in input().split()]
n=s[0]
c=s[1]
s=[int(S) for S in input().split()]
k=1
for i in range(1,n):
    if s[i]-s[i-1]<=c:
        k+=1
    else:
        k=1
print(k)
