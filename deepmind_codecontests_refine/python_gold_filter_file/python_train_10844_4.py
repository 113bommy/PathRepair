n=int(input())
for i in range(n):
    a=input()
    b=input()
    if(len(b)<len(a)):
        print("NO")
        continue
    ans1=[]
    c=1
    for i in range(len(a)-1):
        if(a[i]!=a[i+1]):
            ans1.append([a[i],c])
            c=1
        else:
            c=c+1
    ans1.append([a[-1],c])
    ans2=[]
    c=1
    for i in range(len(b)-1):
        if(b[i]!=b[i+1]):
            ans2.append([b[i],c])
            c=1
        else:
            c=c+1
    ans2.append([b[-1],c])
    if(len(ans1)!=len(ans2)):
        print("NO")
        continue
    c=0
    for i in range(len(ans1)):
        if(ans1[i][0]==ans2[i][0] and ans1[i][1]<=ans2[i][1]):
            c=c+1
    if(c==len(ans1)):
        print("YES")
    else:
        print("NO")