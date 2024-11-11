n=int(input())
l=list(map(int,input().split()))
u=[]
if n==len(l):
    for i in l:
        if i not in u:
            u.append(i)
o=sorted(u)
if len(o)>1:
    
    print(o[1])
else:
    print("NO")
