n, d = map(int, input().split())
a = input()
count = 0
dc = d
while True:
    if d < len(a):
        if a[d] == '1':
            count += 1
            a = a[d:]
            d = dc
        elif d == 1:
            print(-1)
            break
        else:
            d -= 1
    else:
        d-=1
    if d < 1 and count == 0:
        print(-1)
        break
    elif d < 1 and count > 0:
        print(count)
        break

        
