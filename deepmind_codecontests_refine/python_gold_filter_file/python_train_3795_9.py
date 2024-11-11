n = int(input())
k=0
p=1
t=0
for i in range(n):
    for j in range(n//2-k):
        print("*",end='')
    for j in range(p):
        print("D", end='')
    for j in range(n//2-k):
        print("*",end='')
    print(end='\n')
    if p!=n and t==0:
        k+=1
        p+=2
    else:
        t=1
        k-=1
        p-=2
    