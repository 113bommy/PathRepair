#for _ in range(int(input())):
if 1:
    n,k=map(int,input().split())
    s=list(input())
    if n==1:
        if k==0:
            print(*s)
        else:
            print(0)
    else:
     for i in range(0,n):
        if k==0:
            break
        if i==0:
            if s[i]=='1':
                continue
            else:
                s[i]='1'
                k=k-1
                continue
        if s[i]=='0' and i!=0:
            continue
        else:
            if i!=0:
             s[i]='0'
             k=k-1
     print(''.join(s))
            
    
