s1=input()
s2=input()
st=''
d=0
for i in range(len(s1)):
    if ord(s1[i])>ord(s2[i]):
        st=st+s2[i]
    elif ord(s1[i])==ord(s2[i]):
        if s1[i]=="z":
            st=st+"z"
        else:
            st=st+chr(ord(s1[i])+1)
    else:
        d=1
        break
if d==1:
    print(-1)
else:
    print(st)