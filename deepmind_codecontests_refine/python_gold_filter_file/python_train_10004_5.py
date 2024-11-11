n,k=map(int,input().split())
s=input()
gre=n-k
count=0
m=0
for i in range(n):
    if(count>=(k//2)):
        break
    if(s[i]=="("):
        count+=1
        m+=1
        print(s[i],end="")
    if(s[i]==")"):
        m-=1
        print(s[i],end="")

for j in range(m):
    print(")",end="")