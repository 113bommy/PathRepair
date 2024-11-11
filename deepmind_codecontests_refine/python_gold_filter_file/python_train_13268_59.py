n=0
for i in range(int(input())):
    a,b=map(int,input().split())
    if b-a>1:
        n+=1
print(n)