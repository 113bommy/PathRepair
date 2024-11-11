n, k = map(int, input().split())
s = input()
if(k==0):
    print(s)
elif(n==1):
    print("0")
else:
    if(s[0]=='1'):
        k+=1
    print("1",end="")
    for i in range(1,len(s)):
        if(k-1>0 and s[i]!='0'):
            print("0",end="")
            k-=1
        else:
            print(s[i],end="")
