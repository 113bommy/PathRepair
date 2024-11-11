for _ in range(int(input())):
    s,m=input(),input()
    res=0
    for i in range(len(m)-1):
        j=s.index(m[i])
        res=res+abs(j-s.index(m[i+1]))
    print(res)