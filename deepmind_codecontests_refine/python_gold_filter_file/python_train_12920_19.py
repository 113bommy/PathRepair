con=[]
for i in range(int(input())):
    a=list(input())
    con.append(a)
for i in range(len(con)):
    s=con[i]
    #print(s)
    var=""
    if not any(c.isupper() for c in s):
        var+="A"
    if  not any(map(str.isdigit, s)):
        var+="1"
    if  not any(c.islower() for c in s):
        var+="a"
    #print(var)
    if len(var)==2:
        s[0]=var[0]
        s[1]=var[1]
        print("".join(s))
    elif len(var)==0:
        print("".join(s))
    else:
        d=0
        l=0
        u=0
        for j in range(len(s)):
            if s[j].isdigit() and d==0:
                #ls.append(s[j])
                d=1
            elif s[j].isdigit() and d==1:
                s[j]=var[0]
                print("".join(s))
                break
            elif s[j].islower() and l==0:
                #ls.append(s[j])
                l=1
            elif s[j].islower() and l==1:
                s[j]=var[0]
                print("".join(s))
                break
            elif s[j].isupper() and u==0:
                #ls.append(s[j])
                u=1
            elif s[j].isupper() and u==1:
                s[j]=var[0]
                print("".join(s))
                break
            '''if len(ls)==2:
                s[j+1]=var[0]
                print("".join(s))
                break'''
