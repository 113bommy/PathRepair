
l,r=map(int,input().split())
flag=0
for i in range(l,r+1):

    s=str(i)
    k=set(s)
    if(len(k)==len(s)):
        flag=1
        print(i)
        break
if(flag==0):
    print("-1")

    
