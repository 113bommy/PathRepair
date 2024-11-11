s=list(input())
q=['H','Q','9']
x=0
for i in s:
    if (i in q)==True:
        print("YES")
        break
    else:
        x=x+1
if x==len(s):
    print("NO")