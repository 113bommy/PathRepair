
def main():
    mass = input().split(' ')
    x = int(mass[0])
    y = int(mass[1])
    z = int(mass[2])
    t1 = int(mass[3])
    t2 = int(mass[4])
    t3 = int(mass[5])
    a = (abs(x-y))*t1
    if (x==z):
        b =  abs(x-y)*t2 + 3* t3
    else:
        b = abs(x-z)*t2 + abs(x-y)*t2 + 3* t3
    
    if (b<=a):   
        print("YES")
    if (b>a):   
        print("NO")
    return 0

main()