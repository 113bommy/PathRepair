def gns():
    return [int(x) for x in input().split()]
n,x=gns()

# if len(str(x))>n:
#     n+=1
if n==1:
    if x==1:
        print(0)
        quit()
    print(1)
    print(1)
    quit()
b=len(bin(x))-2
if x!=1:
    ans=[1]
else:
    ans=[2]
cur=1
for i in range(n-2):
    if cur==b-1:
        cur+=1
    ans=ans+[1<<cur]+ans
    cur+=1
if x>=(1<<n):
    ans=ans+[1<<cur]+ans
# y=((1<<n)-1)^x
y=x
# if x<(1<<n) and (x+1)!=(1<<n):
#     ans=[c^y for c in ans]
print(len(ans))
print(' '.join(map(str,ans)))
