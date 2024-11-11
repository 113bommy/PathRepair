n=int(input())
p=0
for i in range(n):
    a,b=map(int,input().split())
    if b-a>=2:
        p+=1
print(p)