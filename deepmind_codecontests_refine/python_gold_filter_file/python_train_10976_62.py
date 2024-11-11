n,k=map(int,input().split())
a=list(map(int,input().split()))
p=0
for i in a:
    if 5-i>=k:
        p+=1
print(p//3)