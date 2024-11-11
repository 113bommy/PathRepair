S=list(str(input()))
temp=[]
ans=0
last=[]
for i in range(len(S)):
    temp.append(S[i])
    if temp!=last:
        last=temp
        temp=[]
        ans+=1

    
print(ans)
