nk=input().split()
n=int(nk[0])
k=int(nk[1])
for _ in range(k):
    if n%10!=0:
        n=n-1
    else:
        n=n//10
print(n)