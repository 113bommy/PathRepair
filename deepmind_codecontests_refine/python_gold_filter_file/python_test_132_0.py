for _ in range(int(input())):
    b = list(map(int,input().split()))
    a=[]
    a1=b[-1]-b[-2]
    a2=b[-1]-b[-3]
    a3=b[-1]-a1-a2
    a.append(a1)
    a.append(a2)
    a.append(a3)
    print(a1,a2,a3)