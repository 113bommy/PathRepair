a,b=[int(i) for i in input().split()]
if(a==0):
    print(-b**2)
    print('x'*b)
elif(b==0):
    print(a**2)
    print('o'*a)
elif(b==1):
    print(a**2-1)
    print('x'+'o'*a)
else:
    ans=-float('inf')
    gr_no=None
    for i in range(2,min(a+2,b+1)):
        v1=(a+2-i)**2 + i-2
        quo=b//i
        rem=b%i
        v2=rem*((quo+1)**2) + (i-rem)*((quo**2))
        if(v1-v2>ans):
            gr_no=i
            ans=v1-v2
    quo=b//gr_no
    rem=b%gr_no
    if(rem>0):
        s='x'*(quo+1)+'o'*(a+2-gr_no)
        rem-=1
    else:
        s='x'*(quo)+'o'*(a+2-gr_no)
    gr_no-=1
    s1='x'*(quo+1)+'o'
    s2='x'*quo + 'o'
    for i in range(rem):
        s+=s1
    for i in range(gr_no-rem-1):
        s+=s2
    s+='x'*(quo)
    print(ans)
    print(s)


