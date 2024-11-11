n=int(input())
k=0
for i in range(n):
    p,c=map(int,input().split())
    if (c-p)>1:
        k+=1
print(k)