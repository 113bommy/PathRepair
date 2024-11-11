n= int(input())
c=0
for i in range(n):
    a,b = map(int,input().split())
    if b-1>a:
        c+=1
print(c)
