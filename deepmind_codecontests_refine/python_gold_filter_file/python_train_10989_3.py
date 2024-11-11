def swap(t1, t2):
    return t2, t1
c =int(input())
lim = 64
ans = 1
now = 2
pre = 1
while(now<c):
    pre+=now+1
    pre,now = swap(pre,now)
    ans+=1
if(c<=2):
    print(c-1)
else:
    print(ans)