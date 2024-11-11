x,t,a,b,da,db=map(int,input().split())
case=False
for fa in range(2):
    for fb in range(2):
        for i in range(t):
            for j in range(t):
                if(fa*a-fa*(i*da)+fb*b-fb*(j*db)==x):
                    case=True
if(case):
    print("YES")
else:
    print("NO")
