t = int(input())
for i in range(t):
    j = int(input())
    num = "11"
    for k in range(j):
        print(k+2, end = '')
        num += '1'
        if k<j-1:
            print(' ', end = '')
    print()