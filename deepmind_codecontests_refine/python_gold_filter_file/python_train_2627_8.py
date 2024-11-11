n=int(input())
l=list(map(int,input().split()))
maxa=0
string=""
a=[]
for i in range(0,n):
    a.append(l[i]+maxa)
    if(a[i]>maxa):
        maxa=a[i]
    else:
        continue
for i in range(n):
    string+=str(a[i])+' '
print(string)    
    


