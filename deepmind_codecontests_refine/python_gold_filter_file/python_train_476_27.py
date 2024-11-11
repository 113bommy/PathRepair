a = list(map(int,input().split()))
ta = a[0]*a[1]+2*a[3]
tb = a[0]*a[2]+2*a[4]
if ta<tb:
    print("First")
elif ta>tb:
    print("Second")
else :
    print("Friendship")