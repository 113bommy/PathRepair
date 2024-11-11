n,m=map(int,input().split())
a=list(map(int,input().split()))
d={}
a.sort()

low=1
high=m

for i in a:
    d[i]=2

from collections import deque

def check(mid,a):
    s=0
    for i in range(n-1):
        s+=min(2*mid,a[i+1]-a[i]-1)
    if s+ 2*mid>=m:
        return True
    else:
        return False
        
    

while low<high:
    mid=(low+high)//2
    if check(mid,a):
        high=mid
    else:
        low=mid+1

st=deque(a)
# print(st)
k=0
ans=[]
pr=0
while m>0:
    if st[0]==a[0]:
        k+=1
        
    if st[0]-k  in d and st[0]+k in d:
        st.popleft()
        continue
    # print(ans)
    if st[0]-k  not in d:
        d[st[0]-k]=1
        m-=1
        pr+=k
        ans.append(st[0]-k)
    # print(ans)    
    if st[0]+k  not in d and m>0:
        d[st[0]+k]=1
        m-=1
        pr+=k
        ans.append(st[0]+k)
    # print(ans)    
    st.append(st.popleft())
    
print(pr)    
print(*ans)        