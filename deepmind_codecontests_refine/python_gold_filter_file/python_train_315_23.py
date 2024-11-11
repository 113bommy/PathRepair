even = "#." * 151
odd = ".#" * 151
while 1:
    h,w = map(int,input().split())
    if h == w ==0:
        break
    for i in range(h//2):
        print(even[:w])
        print(odd[:w])
    if h%2 != 0:
        print(even[:w])
    print()