#map(int,input().split())
n=int(input())
s=list(input())
cnt=[[0]*3 for i in range(3)]
f=[0]*3
for i in range(n):
    f[i%3]+=1
    if s[i]=='R':
       cnt[i%3][0]+=1
    if s[i]=='G':
       cnt[i%3][1]+=1
    if s[i]=='B':
       cnt[i%3][2]+=1
a=[10**6]*6
a[0]=f[0]-cnt[0][0]+f[1]-cnt[1][1]+f[2]-cnt[2][2]
a[1]=f[0]-cnt[0][0]+f[1]-cnt[1][2]+f[2]-cnt[2][1]
a[2]=f[0]-cnt[0][1]+f[1]-cnt[1][0]+f[2]-cnt[2][2]
a[3]=f[0]-cnt[0][1]+f[1]-cnt[1][2]+f[2]-cnt[2][0]
a[4]=f[0]-cnt[0][2]+f[1]-cnt[1][0]+f[2]-cnt[2][1]
a[5]=f[0]-cnt[0][2]+f[1]-cnt[1][1]+f[2]-cnt[2][0]
m=min(a)
ans=0
if m==a[0]:
   for i in range(n):
       if i%3==0 and s[i]!='R':
          s[i]='R'
          ans+=1
       if i%3==1 and s[i]!='G':
          s[i]='G'
          ans+=1
       if i%3==2 and s[i]!='B':
           s[i]='B'
           ans+=1
   print(ans)
   print(''.join(s))
elif m==a[1]:
    for i in range(n):
        if i % 3 == 0 and s[i] != 'R':
            s[i] = 'R'
            ans += 1
        if i % 3 == 1 and s[i] != 'B':
            s[i] = 'B'
            ans += 1
        if i % 3 == 2 and s[i] != 'G':
            s[i] = 'G'
            ans += 1
    print(ans)
    print(''.join(s))
elif m==a[2]:
    for i in range(n):
        if i % 3 == 0 and s[i] != 'G':
            s[i] = 'G'
            ans += 1
        if i % 3 == 1 and s[i] != 'R':
            s[i] = 'R'
            ans += 1
        if i % 3 == 2 and s[i] != 'B':
            s[i] = 'B'
            ans += 1
    print(ans)
    print(''.join(s))
elif m==a[3]:
    for i in range(n):
        if i % 3 == 0 and s[i] != 'G':
            s[i] = 'G'
            ans += 1
        if i % 3 == 1 and s[i] != 'B':
            s[i] = 'B'
            ans += 1
        if i % 3 == 2 and s[i] != 'R':
            s[i] = 'R'
            ans += 1
    print(ans)
    print(''.join(s))
elif m==a[4]:
    for i in range(n):
        if i % 3 == 0 and s[i] != 'B':
            s[i] = 'B'
            ans += 1
        if i % 3 == 1 and s[i] != 'R':
            s[i] = 'R'
            ans += 1
        if i % 3 == 2 and s[i] != 'G':
            s[i] = 'G'
            ans += 1
    print(ans)
    print(''.join(s))
else:
    for i in range(n):
        if i % 3 == 0 and s[i] != 'B':
            s[i] = 'B'
            ans += 1
        if i % 3 == 1 and s[i] != 'G':
            s[i] = 'G'
            ans += 1
        if i % 3 == 2 and s[i] != 'R':
            s[i] = 'R'
            ans += 1
    print(ans)
    print(''.join(s))