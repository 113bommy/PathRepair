a , b = input().split()

a = int(a)
b = int(b)
count = 0
count = int(count)
for i in range(0,a):
    symbol , val = input().split()
    val = int(val)
    if symbol=="+":
        b = b + val
    elif symbol=="-":
        if b>=val:
            b = b - val
        else:
            count = count + 1

print(b,count,sep=" ")