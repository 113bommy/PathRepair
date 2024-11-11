input()
s=list(map(int,input().split()))
cnt=0
#-1 -1 2 -1 -1 -1 -1 -1 -1 -1 -1
flag=0
for i in s:
    if i is -1:
        if flag==0:
            cnt+=1
        else:
            flag-=1
    elif i!=-1:
        flag+=int(i)
print(cnt)
