i = int(input())

for _ in range(i):
    a, b = map(int, input().split())
    
    if (a == b): 
        print(0)
        continue
    c = abs(a - b)
    if c < 10:
        print(1)
        continue
    d = int(c/10)
    if c % 10 != 0:
        d +=1

    print(d)