t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    c = 0
    d = 0
    x = 1 
    a = "01"*(n//2) 
    b = "10"*(n//2)
    for i in range(n-1):
        if s[i]==s[i+1] and s[i]=='1':
            c+=1
        if s[i]==s[i+1] and s[i]=='0':
            d+=1 
    if c==0 and d==0:
        print(0)
    else:
        if c==0:
            print(d)
        elif d==0:
            print(c)
        else:
            print(max(c,d))
