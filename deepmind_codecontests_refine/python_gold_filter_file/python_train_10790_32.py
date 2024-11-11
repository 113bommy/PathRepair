l,r,a=map(int,input().split())
k=min(l,r)
if k+a==max(l,r):
    print(2*(k+a))
elif k+a>max(l,r) and k!=0:
    c=a-(max(l,r)-k)
    c=c//2
    print(2*(max(l,r)+c))
elif min(l,r)==0:
    if max(l,r)>a:
        print(a)
    else:
        print(2*(max(l,r)+(a-max(l,r))//2))
elif k+a<max(l,r) and k!=0:
    print(2*(k+a))
    

