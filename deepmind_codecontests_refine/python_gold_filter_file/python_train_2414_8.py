n =int(input())
s = input()
ans = s[:n]
if n == len(s):
    ans = list(ans)
    for i in range(n-1,-1,-1):
        if ans[i] != "9": ans[i] = chr(ord(ans[i])+1);break
        else:ans[i] = chr(ord("0"))
    ans = "".join(ans)
    print(ans)
elif(len(s)%n) or ans == "9"*n:
    print(("1"+"0"*(n-1))*(len(s)//n + 1))
else:
    
    ch =1
    for i in range(n,len(s)-n+1,n):
        if s[:n] > s[i:i+n]:ch=0;break

    if ch:
        ans = list(ans)
        for i in range(n-1,-1,-1):
            if ans[i] != "9": ans[i] = chr(ord(ans[i])+1);break
            else:ans[i] = chr(ord("0"))
        
        # if n==12345 and s[0]=='3': ans[-1] = "7"
        ans = "".join(ans)

    print(ans*(len(s)//n))