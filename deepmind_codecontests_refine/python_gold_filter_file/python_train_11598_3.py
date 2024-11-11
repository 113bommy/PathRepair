a=list(input())
for i in range(0,len(a)-2):
    if a[i]=='1' and a[i+1]=='4' and a[i+2]=='4':
        a[i]='+'
        a[i+1]='+'
        a[i+2]='+'
for i in range(0,len(a)-1):
    if a[i]=='1' and a[i+1]=='4':
        a[i]='+'
        a[i+1]='+'
for i in range(0,len(a)):
    if a[i]=='1':
        a[i]='+'
flag=1
for i in range(0,len(a)):
    if a[i]!='+':
        print("NO")
        flag=0
        break
if flag==1:
    print("YES")