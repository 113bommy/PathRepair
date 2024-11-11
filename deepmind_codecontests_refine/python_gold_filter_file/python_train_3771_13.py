#t = int(input())
t=1
while t!=0:
    t-=1 
    n = int(input())
    s = input()
    aux = 'abcdefghijklmnopqrstuvwxyz'
    maxi = [0 for _ in range(26)]
    dp = [1 for _ in range(n)]
    for i in range(n):
        for j in range(aux.find(s[i])+1 , 26):
            dp[i] = max(dp[i], maxi[j]+1)
        maxi[aux.find(s[i])] = dp[i] 
    
    st = set(dp)
    print(len(st))
    print(*dp)
        

        
    