n=int(input())
a=[]
kol=0
for i in range(n):
    z,t=map(int,input().split())
    a.append([z,t])
for i in range(n-1):
    for j in range(i+1,n):
        if a[i][0]==a[j][1]:
            kol+=1
        if a[i][1]==a[j][0]:
            kol+=1
print(kol)
