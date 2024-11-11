n=int(input())
a=list(map(int, input().split()))
chest,biceps,back=a[0],0,0
for i in range(1,n):
    if i%3==0:
        chest+=a[i]
    elif (i-1)%3==0:
        biceps+=a[i]
    else:
        back+=a[i]
if chest>biceps and chest>back:
    print('chest')
elif biceps>chest and biceps>back:
    print('biceps')
else:
    print('back')
    
