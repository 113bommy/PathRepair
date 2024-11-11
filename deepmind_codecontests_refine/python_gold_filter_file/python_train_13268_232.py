t=int(input())
c=0
for i in range(t):
    p,q=map(int,input().split(" "))
    if(abs(p-q)>=2):
        c+=1
print(c)