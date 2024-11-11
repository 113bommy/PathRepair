n,p,k = map(int,input().split())
if((p-k)>1):
    print("<<",end=" ")
for i in range(p-k,p+k+1):
    if(i<1) or (i>n):
        continue
    elif(i==p):
        print("(" + str(i) + ")",end=" ")
    else:
        print(str(i),end=" ")
if((p+k)<n):
    print(">>")