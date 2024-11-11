a=[['\'',',','.','!','?'],
   ['a','b','c','A','B','C'],
   ['d','e','f','D','E','F'],
   ['g','h','i','G','H','I'],
   ['j','k','l','J','K','L'],
   ['m','n','o','M','N','O'],
   ['p','q','r','s','P','Q','R','S'],
   ['t','u','v','T','U','V'],
   ['w','x','y','z','W','X','Y','Z']]
while 1:
    try:b=input()+'@'
    except:break
    c=0
    ans=''
    for i in range(len(b)-1):
        if b[i]!=b[i+1]:
            if b[i]!='0':
                d=int(b[i])-1
                ans+=a[d][c%len(a[d])]
            c=0
        else: c+=1
        if b[i]==b[i+1]=='0':ans+=' '
    print(ans)