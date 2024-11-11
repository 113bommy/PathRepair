n=int(input())
l=list(map(int,input().split()))
d={}
a={}
c={}
for i in range(len(l)):
    if(l[i] in d):
        if(c[l[i]]==0):
            a[l[i]]=i-d[l[i]];
            d[l[i]]=i;
            c[l[i]]=c[l[i]]+1
        else:
            if(i-d[l[i]]==a[l[i]]):
                c[l[i]]=c[l[i]]+1
                d[l[i]]=i
            else:
                a[l[i]]=-1
        
    else:
        d[l[i]]=i
        c[l[i]]=0
        a[l[i]]=0
li=0
for j in a:
    if(a[j]!=-1):
        li=li+1
print(li)
l.sort()
l=set(l)
for j in l:
    if(a[j]!=-1):
        print(j,a[j])
    