n=int(input())
s=0
for i in range(n):
    p,q=map(int,input().split())
    if (q-p>1):
        s+=1
print(s)