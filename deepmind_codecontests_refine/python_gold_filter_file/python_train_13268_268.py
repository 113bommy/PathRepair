q=int(input())
s=0
for i in range(q):
    z,x=map(int,input().split())
    if x-z>1:
        s+=1
print(s)
