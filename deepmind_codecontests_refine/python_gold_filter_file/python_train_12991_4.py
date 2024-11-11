import sys
input=sys.stdin.readline
n=int(input())
if n<20:
    if n==2:
        print(-1)
    elif n==7:
        print('aabbcc.')
        print('dd.dd.a')
        print('..d..da')
        print('..d..db')
        print('dd.dd.b')
        print('..d..dc')
        print('..d..dc')
    elif n%3==0:
        x=n//3
        for i in range(x):
            print('...'*i+'a..'+'...'*(x-1-i))
            print('...'*i+'a..'+'...'*(x-1-i))
            print('...'*i+'.bb'+'...'*(x-1-i))
    elif n%4==0:
        x=n//4
        for i in range(x):
            print('....'*i+'abcc'+'....'*(x-1-i))
            print('....'*i+'abdd'+'....'*(x-1-i))
            print('....'*i+'eegh'+'....'*(x-1-i))
            print('....'*i+'ffgh'+'....'*(x-1-i))
    elif n%5==0:
        x=n//5
        for i in range(x):
            print('.....'*i+'aabcc'+'.....'*(x-1-i))
            print('.....'*i+'d.b.f'+'.....'*(x-1-i))
            print('.....'*i+'d.eef'+'.....'*(x-1-i))
            print('.....'*i+'gg.ij'+'.....'*(x-1-i))
            print('.....'*i+'.hhij'+'.....'*(x-1-i))
    elif n==11:
        print('a..cee'+'.....')
        print('a..c.f'+'.....')
        print('.bbddf'+'.....')
        print('ceea..'+'.....')
        print('c.fa..'+'.....')
        print('ddf.bb'+'.....')
        print('......'+'aabcc')
        print('......'+'d.b.f')
        print('......'+'d.eef')
        print('......'+'gg.ij')
        print('......'+'.hhij')
    else:
        if n%5==0:
            a=0
            b=n//5
        elif n%5==1:
            a=4
            b=(n-16)//5
        elif n%5==2:
            a=3
            b=(n-12)//5
        elif n%5==3:
            a=2
            b=(n-8)//5
        elif n%5==4:
            a=1
            b=(n-4)//5
        x=a
        for i in range(x):
            print('....'*i+'abcc'+'....'*(x-1-i)+'.....'*b)
            print('....'*i+'abdd'+'....'*(x-1-i)+'.....'*b)
            print('....'*i+'eegh'+'....'*(x-1-i)+'.....'*b)
            print('....'*i+'ffgh'+'....'*(x-1-i)+'.....'*b)
        x=b
        for i in range(x):
            print('....'*a+'.....'*i+'aabcc'+'.....'*(x-1-i))
            print('....'*a+'.....'*i+'d.b.f'+'.....'*(x-1-i))
            print('....'*a+'.....'*i+'d.eef'+'.....'*(x-1-i))
            print('....'*a+'.....'*i+'gg.ij'+'.....'*(x-1-i))
            print('....'*a+'.....'*i+'.hhij'+'.....'*(x-1-i))
else:
    if n%5==0:
        a=0
        b=n//5
    elif n%5==1:
        a=4
        b=(n-16)//5
    elif n%5==2:
        a=3
        b=(n-12)//5
    elif n%5==3:
        a=2
        b=(n-8)//5
    elif n%5==4:
        a=1
        b=(n-4)//5
    x=a
    for i in range(x):
        print('....'*i+'abcc'+'....'*(x-1-i)+'.....'*b)
        print('....'*i+'abdd'+'....'*(x-1-i)+'.....'*b)
        print('....'*i+'eegh'+'....'*(x-1-i)+'.....'*b)
        print('....'*i+'ffgh'+'....'*(x-1-i)+'.....'*b)
    x=b
    for i in range(x):
        print('....'*a+'.....'*i+'aabcc'+'.....'*(x-1-i))
        print('....'*a+'.....'*i+'d.b.f'+'.....'*(x-1-i))
        print('....'*a+'.....'*i+'d.eef'+'.....'*(x-1-i))
        print('....'*a+'.....'*i+'gg.ij'+'.....'*(x-1-i))
        print('....'*a+'.....'*i+'.hhij'+'.....'*(x-1-i))
        
    
