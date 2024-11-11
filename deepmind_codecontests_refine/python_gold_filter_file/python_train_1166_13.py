def sol():
    A=[]
    for i in range(6):
        A.append(int(input()))
    t,s,v,j,e,f=map(int,A)
    p=0
    if(e>f):
        if(t>j):
            p=j*e
            j=0
        else:
            p=t*e
            j=j-t
        p=p+(min(s,v,j)*f)
    else:
        q=min(s,v,j)
        j=j-q
        p=f*q+(min(t,j)*e)
    print(p)
if(__name__=='__main__'):
    sol()
