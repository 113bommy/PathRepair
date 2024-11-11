n, m, s, f = map(int, input().split())
l = []
for i in range(m):
    t, c,r = map(int, input().split())
    l.append([t, c, r])
if s > f:
    st = ""
    t = 1
    i = 0
    while(i<m):
        if t == l[i][0]:
             
            if (s<l[i][1] or s>l[i][2]) and (s-1<l[i][1] or s-1>l[i][2]):
                s-=1
                st+="L"
            else:
                st+="X"
            i+=1
            if s == f:
                break
        else:
            st+='L'
            s-=1
            if s == f:
                break
        t+=1
    while(s>f):
        s-=1
        st+='L'
    print(st)
if s<f:
    st = ""
    t = 1
    i = 0
    while(i<m):
        
        if t == l[i][0]:
            if (s<l[i][1] or s>l[i][2]) and (s+1<l[i][1] or s+1>l[i][2]):
                s+=1
                st+="R"
            else:
                st+="X"
            i+=1
            if s == f:
                break
        else:
            st+='R'
            s+=1
            if s == f:
                break
        t+=1
    while(s<f):
        s+=1
        st+='R'
    print(st)
