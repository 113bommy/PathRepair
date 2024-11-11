a = list(map(int, input().split()))
if (a[1]*a[0]+a[3]*2) < (a[2]*a[0]+a[4]*2):
    print('First')
elif  (a[1]*a[0]+a[3]*2) > (a[2]*a[0]+a[4]*2):
    print('Second')
else:
    print('Friendship')