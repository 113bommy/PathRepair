n,k=[int(x) for x in input().split()]
a=[int(x) for x in input().split()]
b=[int(x) for x in input().split()]
p=set()
q=set()
literals=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
it=0
s=[0]*n
for i in range(n):
    p.add(a[i])
    q.add(b[i])
    s[a[i]-1]=literals[it]
    if a[i] in q:
        q.remove(a[i])
        p.remove(a[i])
    if b[i] in p:
        p.remove(b[i])
        q.remove(b[i])
    if not p and (not q):
        it=min(it+1,25)
        k-=1
if k<=0:
    arr=''
    print('YES')
    for item in s:
        arr+=item
    print(arr)
else:
    print('NO')
