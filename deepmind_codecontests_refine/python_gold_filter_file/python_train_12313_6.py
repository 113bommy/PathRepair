
def get_prev_count(y):
    if y == 0:
        return 0
    elif y % 2 == 0:
        return -1 + 3*(y//2)
    else:
        return 1 + 3*(y//2)
        
a, x, y = [int(x) for x in input().split()]
if y % a == 0:
    print(-1)
else:
    y = y//a #Номер ряда
    even = True if y!=0 and y%2==0 else False
    prev_count = get_prev_count(y)
    if even and abs(x)<a and x != 0 or not even and abs(x)*2 < a:
        print(prev_count+(2 if even and x>0 else 1))
    else:
        print(-1)
