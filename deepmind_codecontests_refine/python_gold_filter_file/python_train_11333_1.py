w,h = map(int,input().split())
arr=[]
for i in range(w):
    arr.append( (int(input()),'p') )
for i in range(h):
    arr.append( (int(input()),'q') )
arr.sort()
#print(arr)
ans=0
for a in arr:
    if a[1]=='p':
        ans+=a[0]*(h+1)
        w-=1
    else:
        ans+=a[0]*(w+1)
        h-=1
print(ans)
