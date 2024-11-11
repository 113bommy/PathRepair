n=int(input())
a=list(map(int,input().split()))
li=[]
for i in range(n):
    li.append([a[i],i+1])
b=sorted(li,key=lambda x:x[0],reverse=True)

shots=0
for i in range(n):
    shots+=b[i][0]*i+1
print(shots)
for i in b:
    print(i[1],end=" ")