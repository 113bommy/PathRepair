for i in range(int(input())):
    a = input()
    s = len(a)
    if s<=10:
        print(a)
    else:
        b = a[1:-1]
        print("%s%s%s" % (a[0],str(len(b)),a[-1]))