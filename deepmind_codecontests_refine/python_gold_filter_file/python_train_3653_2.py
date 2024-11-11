z,o,x=map(int,input().split())
s="0"*z
if o>0:
    s,o="1",o-1
    for i in range(x):
        if s[i]=='0' and o>0:
            s,o,x=s+'1',o-1,x-1
        if s[i]=='1' and z>0:
            s,z,x=s+'0',z-1,x-1
    if x>0 and z>0:
        s,z='0'+s,z-1
    if s[0]=='0':
        s='0'*(z+1)+'1'*o+s[1::]
    else:
        s='1'*(o+1)+'0'*z+s[1::]
print(s)