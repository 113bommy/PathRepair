# t=int(input())
t=1
for _ in range(t):
    s=input()
    n=len(s);
    if(n<=3):print(s[0]);exit(0);
    finl_Str="";
    for i in range(0,n,2):
        if(n-i-2<=i+1):break;
        if('a' in s[i:i+2] and 'a' in s[n-i-2:n-i]):
            finl_Str+='a'
        elif('b' in s[i:i+2] and 'b' in s[n-i-2:n-i]):
            finl_Str+='b'
        elif('c' in s[i:i+2] and 'c' in s[n-i-2:n-i]):
            finl_Str+='c'
    ans=""
    if(n%4):ans=finl_Str+s[n//2]+finl_Str[::-1]
    else:ans=finl_Str+finl_Str[::-1]
    print(ans)