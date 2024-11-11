n,k=map(int,input().split())
a=input()
p=0
for i in range(n-1):
    if a[i]==a[i+1]:
        p+=1
print(min(p+2*k,n-1))