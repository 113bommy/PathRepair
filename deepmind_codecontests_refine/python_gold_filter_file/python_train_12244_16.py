n,k=map(int,input().split())
l=input()
d={}
for i in l:
    d[i]=d.get(i,0)+1
for i in d.values():
    if i>k:
        print("NO")
        break
else:
    print("YES")