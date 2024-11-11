for _ in range(int(input())):
    a,k=map(int,input().split())
    for i in range(k-1):
        b=a+int(min(str(a)))*int(max(str(a)))
        a=b
        if "0" in str(b):
            break
    print(a)