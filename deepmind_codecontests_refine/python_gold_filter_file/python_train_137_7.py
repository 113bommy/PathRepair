N=int(input())
A=input()
dic={}
for i in A:
    if i in dic:
        dic[i]+=1
    else:
        dic[i]=1
ans=[]
flag=0
for i in dic:
    temp=[]
    if dic[i]%N==0:
        res=dic[i]//N
        temp=[i]*res
        ans.append(temp)
    else:
        print(-1)
        flag=1
        break
if flag==0:
    ans=ans*N
    for i in ans:
        print(*i,sep='',end='')
