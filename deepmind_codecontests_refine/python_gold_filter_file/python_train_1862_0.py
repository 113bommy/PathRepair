while True:
    try:
        a = int(input())
    except:
        break
    tmp = a - (a // 39) * 39
    print("3C{:02d}".format(tmp if tmp % 39 else 39))