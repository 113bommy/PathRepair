for _ in range(int(input())):
    A = input()
    st = input()
    d = dict()
    for i in range(26):
        d[A[i]]  =i
        
    if len(st) ==0:
        print(0)
        continue
    if len(st) ==1:
        print(0)
        continue
    
    k = st[0]
    ans = 0
    for i in range(1,len(st)):
        ans += abs(d[st[i]] - d[k])
        k = st[i]
        
    print(ans)