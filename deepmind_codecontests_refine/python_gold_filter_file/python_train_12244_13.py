n,k=map(int,input().split())
x=input()
q=""
for i in range(len(x)):
    if(len(x)!=n):
        q="NO"
        print("NO")
        break
    if(x.count(x[i])>k):
        q="NO"
        print("NO")
        break

if(q!="NO"):print("YES")