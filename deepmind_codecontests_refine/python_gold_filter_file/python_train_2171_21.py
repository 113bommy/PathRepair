a, b, c = map(int, input().split())

counter = 0
while a%2==b%2==c%2==0:
    a, b, c = (b+c)//2, (a+c)//2, (a+b)//2
    counter += 1
    if counter > 26:
        counter = -1
        break
print(counter)