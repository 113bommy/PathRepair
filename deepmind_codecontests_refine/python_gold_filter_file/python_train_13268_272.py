n=int(input())
k=0
for i in range(n):
    a,b=map(int,input().split())
    if b-a>1:
        k+=1
print(k)
