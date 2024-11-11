n,h=map(int,input().split())
a=list(map(int,input().split()))
s=0
for i in a:
    if(i>h):
        s+=2
    else:
        s+=1
print(s)