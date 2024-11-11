def kenti(a):
    k = 0
    for i in a:
        if i%2==1:
            return False
    return True
n = int(input())
a = list(map(int,input().split()))
if sum(a)%2==1:
    print('First')
elif sum(a)%2==0 and kenti(a):
    print('Second')
else:
    print('First')