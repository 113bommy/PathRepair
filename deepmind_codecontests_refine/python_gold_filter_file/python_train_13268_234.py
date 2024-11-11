n=int(input())
c=0
for i in range(n):
    l,t=map(int,input().split())
    if t-l >=2 :
        c+=1
print(c)
