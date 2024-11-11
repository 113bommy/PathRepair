t=list(input())

g=t[::-1]


for v in g:
    a=int(v)//5
    b=int(v)%5
    if a==0:
        if b==4:
            h='O-|'+'O'*b+'-'
            print(h)
        else:
            h='O-|'+'O'*(b)+'-'+'O'*(4-b)
            print(h)
    else:
        if b==4:
            print('-O|'+'O'*b+'-')
        else:
            print('-O|'+'O'*b+'-'+'O'*(4-b))




