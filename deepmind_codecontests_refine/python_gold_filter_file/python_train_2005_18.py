for i in range(int(input())):
    n=int(input())
    s=input()
    s1=input()
    s=s+'0'
    s1=s1+'0'
    a=[]
    b=[]
    for i in range(1,n+1):
        if(s[i]!=s[i-1]):
            a.append(i)
        if(s1[i]!=s1[i-1]):
            b.append(i)
    for i in range(len(b)):
        a.append(b[len(b)-i-1])
    print(len(a),*a)
        