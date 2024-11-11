n=int(input())
s=input()
rama=[]
for i in range(n):
    rama.append(ord(s[i])-96)
visit=[1 for i in range(27)]
a=[]
maxi=0
for i in range(n):
    p=visit[rama[i]]
    a.append(p)
    maxi=max(maxi,p)
    for j in range(rama[i]):
        visit[j]=max(visit[j],p+1)
print(maxi)
for i in a:
    print(i,end=' ')