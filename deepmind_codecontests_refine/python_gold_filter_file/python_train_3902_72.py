line=input()
N,M=line.split()
n,m=int(N),int(M)
list1=[]
c=n//2+1
list3=["."]*(m-1)
list3.append("#")
list4=["#"]
list4.extend(["."]*(m-1))
for i in range(0,c,1):
    list1.append(["#"]*m)
for i in range(1,n-c+1,1):
    if i%2!=0:
        list1.insert(2*i-1,list3)
    else:
        list1.insert(2*i-1,list4)
for i in range(0,n,1):
    for j in range(0,m,1):
        print(list1[i][j],end="")
        if j==m-1:
            print()
