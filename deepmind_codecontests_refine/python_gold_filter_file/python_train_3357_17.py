from sys import stdin, stdout
"""
    n = stdin.readline()
    arr = [int(x) for x in stdin.readline().split()]
    stdout.write(str(summation))
"""
for test in range(int(stdin.readline())) :
    arr = [int(x) for x in stdin.readline().split()]
    n = arr[0]
    k = arr[1]

    if k<n :
        print(k)
    
    elif n==k :
        print(n+1)

    else :
        num = k//(n-1)

        if k%(n-1) == 0 :
            print((n*(num))-1)
        else :
            print((n*num) + (k%(n-1)))
