t=int(input())
while t:
    t-=1
    n,a,b=input().split()
    n,a,b=int(n),int(a),int(b)
    char=97
    string=""
    for i in range(n):        
        if i>b-1:
            break
        else:
            string=string+chr(char+i)
    ans=""
    while len(ans)<=n:
        ans=ans+string
        string=string
    print(ans[:n])