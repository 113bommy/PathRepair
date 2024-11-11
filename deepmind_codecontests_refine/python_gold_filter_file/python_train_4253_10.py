s=input()

cnt=0
while len(s)>1:
    if s[0]==s[-1]:
        s= s[1:-1]
    elif s[0]=="x" and s[-1]!="x":
        s = s[1:]
        cnt +=1
    elif s[-1]=="x" and s[0]!="x":
        s = s[:-1]
        cnt +=1
    else:
        cnt=-1
        break
print(cnt)