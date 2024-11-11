'''
Name : Jaymeet Mehta
codeforces id :mj_13
Problem : 
'''
from sys import stdin,stdout
test=int(stdin.readline())
for _ in range(test):
    n=int(stdin.readline())
    a = [int(x) for x in stdin.readline().split()]
    ans=[]
    cnt=0
    for i in range(n):
        if a[i]==0:
            if cnt&1:
                cnt-=1
            ans.extend([1]*(cnt))
            ans.append(0)
            cnt=0
        if a[i]==1:
            cnt+=1
    if cnt&1:
        cnt-=1
    ans.extend([1]*(cnt))
    print(len(ans))
    print(*ans)