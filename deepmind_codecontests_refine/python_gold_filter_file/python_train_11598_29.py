s=input()
flag=False
if s.count('1')+s.count('4')!=len(s):
    print("NO")
else:
    if s[0]=='4':
        flag=False 
    elif s.count('444')>=1:
        flag=False 
    else:
        flag=True 
    if flag:
        print("YES")
    else:
        print("NO")



