a=int(input())
for i in range(a):
    b=input()
    if len(b)>10:
        print("%s%d%s"%(b[0],len(b)-2,b[-1]))
    else:
        print(b)