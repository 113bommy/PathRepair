f=0
import sys
st=-sys.maxsize
end=sys.maxsize
for _ in range(int(input())):
    s=input()
    import sys
    a,b,c=s.split()
    if c=='N':
        if a=='>':
            a='<='
        elif a=='<':
            a='>='
        elif a=='>=':
            a='<'
        elif a=='<=':
            a='>'
        c='Y'
    #print(a,b,c)
    
    if a=='<':
        end=min(end,int(b)-1)
    elif a=='<=':
        end=min(end,int(b))
    elif a=='>':
        st=max(st,int(b)+1)
    elif a=='>=':
        st=max(st,int(b))
        
    #print(st,end)
    if st>end:
        f=1
    
if f==1:
    print('Impossible')
else:
    print((st+end)//2)