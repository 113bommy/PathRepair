

a , b = map(int, input().split())

n = input()

n = list(n)
c = 1

if b == 0:
    print(''.join(n))
    exit()
elif a == 1:
    print(0)
    exit()
elif n[0] != '1':
    n[0] = '1'
    b = b - 1

for i in range(b):
    while 1:
        if c >= a:
            print(''.join(n))
            exit()

        if n[c] != '0':
            n[c] = '0'
            c += 1
            break
        else:
            c += 1
                
        
                
                
print(''.join(n))