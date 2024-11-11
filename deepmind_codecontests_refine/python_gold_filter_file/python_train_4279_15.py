# n=int(input())
# ns=[int(x) for x in input().split()]
# dp=[None]*n
# def greater(i,num):
#     return ns[i]+ns[i+1]>=num
# def biSearch(t,l,r):
#     if r-l<=1:
#         return l
#     m=(l+r)//2
#     if greater(m,t)
#
#
# def update(t):
#     l=ns[t]
n,m,q=[int(x)for x in input().split()]
sn=input()
sm=input()


def eq(i):
    for j in range(m):
        if sn[i+j]!=sm[j]:
            return False
    return True
re=[0]*n
for i in range(n-m+1):
    if eq(i):
        re[i]=1
for i in range(1,n):
    re[i]+=re[i-1]

for i in range(q):
    l,r=[int(x)-1 for x in input().split()]
    if r-l+1<m:
        print(0)
        continue
    if l==0:
        print(re[r-m+1])
    else:
        print(re[r-m+1]-re[l-1])