string=input()
flag=0
for x in string:
    if x in "HQ9":
        flag=1
if flag==1:
    print("YES")
else:
    print("NO")