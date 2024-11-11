n = int(input())
ans=[[1]]
k=0
while k<n:
    k+=1
    for i in range(len(ans)):
        ans[i].extend(ans[i])    
    for i in range(len(ans)):
        ans.append(ans[i][:])
    for i in range(int(len(ans)/2),len(ans)):
        for j in range(int(len(ans[i])/2),len(ans[i])):
            ans[i][j]*=(-1)
#    print(ans)
for i in ans:
    for j in i:
        if j==-1:
            print('*',end='')
        else:
            print('+',end='')
    print()            


