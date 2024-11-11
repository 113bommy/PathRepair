for T in range(int(input())):
    n,a,b = map(int,input().split())
    ans = 'a'
    t = ord('a')
    for i in range(b - 1):
        t+=1
        ans += chr(t)
    for i in range(a - b):
        ans += chr(t)
    i = 0
    k = len(ans)
    while(len(ans)!=n):
        ans += ans[i]
        i+=1
        i = i%k        
    print(ans)    
    
            