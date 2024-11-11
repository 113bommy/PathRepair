t = int(input())
for i in range(t):
    n, a, b = map(int, input().split(' '))
    arr = []
    if (a+b+2)>n or a>(n-1)//2 or b>(n-1)//2:
        print(-1)
    else:
        if abs(b-a)>1:
            print(-1)
        else:
            if a>b:
                for num in range(1, (a+b)//2 + 2):
                    arr.append(num)
                    arr.append(n-num+1)
                for _ in range(n-a, a, -1):
                    arr.append(_)
                
            elif b>a:
                for num in range(1, (a+b)//2 + 2):
                    arr.append(n-num+1)
                    arr.append(num)
                for _ in range(b+1, n-b+1):
                    arr.append(_)
            else:
                for num in range(1, (a+b)//2 + 1):
                    arr.append(n-num+1)
                    arr.append(num)
                for _ in range(n-a, a, -1):
                    if len(arr)<n:
                        arr.append(_)
                    else:
                        break
            print(*arr)
