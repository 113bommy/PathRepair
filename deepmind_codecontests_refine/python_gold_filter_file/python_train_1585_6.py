

for i in range(int(input())):
    a = int(input())
    b = input()
    s = c = 0
    r = ''
    if a == 1:
        print(-1)
    else:
        for i in b:
            s = s + int(i)
            if int(i) % 2 != 0 and c <= 1:
                r += i
                c += 1
                
            
        if s % 2 == 0 and int(b) % 2 != 0:
            print(b)
        elif c <= 1:
            print(-1)
        else:
            print(r)
            