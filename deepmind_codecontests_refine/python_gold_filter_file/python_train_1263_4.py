#1110A
[b,k] = list(map(int,input().split()))
a = list(map(int,input().split()))
odd = 0
if (b%2 == 0):
    if a[k-1] %2 == 0:
        print('even')
    else:
        print('odd')
else:
    for i in range(k):
        if a[i] % 2 == 1:
            odd += 1
    if odd%2 == 0:
        print('even')
    else:
        print('odd')