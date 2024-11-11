s=input()
nb,ns,nc=map(int,input().split())
pb,ps,pc=map(int,input().split())
r=int(input())

cb = s.count('B')
cs = s.count('S')
cc = s.count('C')
l,h = 0,10**14
while h-l>1:
    x= (l+h)//2
    fx = max(0,cb*x-nb)*pb + max(0,cs*x-ns)*ps + max(0,cc*x-nc)*pc
    if fx>r:
        h=x
    else:
        l=x
print(l)
