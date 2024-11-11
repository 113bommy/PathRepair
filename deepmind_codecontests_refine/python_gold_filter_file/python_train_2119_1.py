n,d=map(int,input().split())
a,b=map(int,input().split())
a2=[]
for i in range(n):
    q,w=map(int,input().split())
    a2.append((a*q+w*b,i))
a2.sort()
ans=[]
sumz=0
for i in range(n):
    if sumz+a2[i][0]>d:
        break
    else:
        ans.append(a2[i][1])
        sumz+=a2[i][0]
print(len(ans))
for i in ans:
    print(i+1,end=' ')