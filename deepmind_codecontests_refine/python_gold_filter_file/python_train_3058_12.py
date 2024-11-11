a, b , n = input().split()
#print(a, b ,n)
z = len(a)

n = int(n)
b = int(b)
num = int(a)
check = True

for i in range(10):
    x = num*10 + i
    if(x%b==0):
        print(x, end='')
        print('0'*(n-1))
        check = False
        break
if check:
    print(-1)
