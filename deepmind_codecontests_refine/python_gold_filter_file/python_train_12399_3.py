n=int(input())
a=sorted(list(map(int,input().split())))
b=sorted(list(map(int,input().split())))
s1=s2=0
for i in range(2*n):
    if i%2==0:
        if len(a)>0 and len(b)>0 and a[-1]>b[-1]:
            s1+=a[-1];del a[-1]
        elif len(b)>0:
            del b[-1]
        else:
            s1+=a[-1];del a[-1]
    else:
        if len(a)>0 and len(b)>0 and b[-1]>a[-1]:
            s2+=b[-1];del b[-1]
        elif len(a)>0:
            del a[-1]
        else:
            s2+=b[-1];del b[-1]
print(s1-s2)