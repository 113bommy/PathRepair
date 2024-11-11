n=int(input())
l=list(map(int,input().split(" ")))
m=list(map(int,input().split(" ")))
dic={}
tt={}
for x in range(n):
    tt[m[x]]=x
for x in range(n):
    t=tt[l[x]]
    if (t-x)%n not in dic.keys():
        dic[(t-x)%n]=1
    else:
        dic[(t-x)%n]=dic[(t-x)%n]+1
print(max(dic.values()))        