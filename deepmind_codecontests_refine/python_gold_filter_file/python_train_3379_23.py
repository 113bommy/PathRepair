n = int(input())
a = list(map(int, input().split()))  
b = list(map(int, input().split()))  
p = a[0]
q = b[0]
flag = 0
for i in range(1, n+1):
    if i in a[1:] or i in b[1:] :
        continue
    else:
        flag = 1
        break
if flag ==1:
    print('Oh, my keyboard!')
else:
    print('I become the guy.')
