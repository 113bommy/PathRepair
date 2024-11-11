n = int(input())
l = list(map(int,input().split()))

ll = []
cnt = 1
for i in range(1,n):
    if l[i]!=l[i-1]:
        ll.append(cnt)
        cnt=1
    else:
        cnt+=1
ll.append(cnt)

ans = 0
if len(ll)>1:
    n = len(ll)
    for i in range(n-1):
        ans = max(ans,min(ll[i],ll[i+1]))
        
print(ans*2)
        
        