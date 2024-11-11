n=int(input())
s=input()
d=''
flag=False
x=y='a'
for i in s:
    if i>=x:
        d+='0'
        x=i
    elif i>=y:
        d+='1'
        y=i
    else:
        print("NO")
        flag=True
        break
if not flag:
    print("YES")
    print(d)

    