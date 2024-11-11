a,b=map(int,input().split())
v=max(a,b)
l=[i for i in range(1,7)if 6%i==0 and (7-v)%i==0]
if len(l)>1:
    print(f"{(7-v)//l[-1]}/{(6//l[-1])}")
else:
    print(f"{7-v}/6")
