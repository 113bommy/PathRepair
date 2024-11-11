c=int(input())
a=int(input())
b=int(input())
ans="NO"
for i in range(c//a+1):
    if (c-a*i)%b==0:
        ans="YES\n"+str(i)+" "+str((c-a*i)//b)
        break
print(ans)
