n = int(input())
m = n % 4
 
if m == 0:
    print("1 A")
elif m == 1:
    print("0 A")
elif m == 2:
    print("1 B")
else:
    print("2 A")