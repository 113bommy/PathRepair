n=int(input())
a=list(map(int,input().split()))
likes=dict()
times=dict()
for i in range(len(a)):
    if a[i] not in  likes:
        likes[a[i]] = 1
        times[a[i]] = i
    else:
        likes[a[i]] = likes[a[i]]+1
        times[a[i]] = i
 
mx=0
like=[]
for i in likes:
    if likes[i] > mx:
        mx = likes[i] 
for i in likes:
    if likes[i] == mx:
        like=like+[i]
if len(like) == 1:
    print(like[0])
else:
    slovar={}
    mn=10000
    max_like=0
    for i in range(len(like)):
        slovar[like[i]] = times[like[i]]
    for i in slovar:
        if slovar[i] < mn:
            mn = slovar[i]
            max_like=i

    print(max_like)
    
