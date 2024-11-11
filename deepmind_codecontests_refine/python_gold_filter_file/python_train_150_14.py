n = int(input())
layout = input()
num = 2
def check(n1, n2):
    global num
    k = abs(n2 - n1)
    extra = abs(n2 - n1)
    while max(n2, n1) + k < n:
        if layout[max(n2, n1)+k] != "*":
            break
        else:
            k += extra
            num += 1
for n1 in range(0, n):
    for n2 in range(0, n):
        num = 2
        if layout[n1] == "*" and layout[n2] == "*" and n1 != n2:
            check(n1, n2)
            if num >= 5:
                break
        if num >= 5:
            break
    if num >= 5:
        break
                    
if num < 5:
    print ("no")
else:
    print ("yes")

